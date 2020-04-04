#include "Scoreboard.h"
#include "Colors.h"

//===============
// Constructor
//===============
Scoreboard::Scoreboard()
{
  FastLED.addLeds<WS2812B, SCOREBOARD_DATA_PIN, GRB>(m_ledMatrix, m_numLeds);
}

Scoreboard::~Scoreboard()
{
  delete m_ballSpriteViewer;
  m_ballSpriteViewer = nullptr;

  for (int i = 0; i < sizeof(m_numberSprites) / sizeof(m_numberSprites[0]); i++)
  {
    delete m_numberSprites[i];
    m_numberSprites[i] = nullptr;
  }
}

//===============
// Public functions
//===============

void Scoreboard::Reset()
{
  m_currentRow = 0;
  m_currentColumn = 0;

  ClearMatrix();
}

bool Scoreboard::Update(GameState& state)
{
  bool animationComplete = false;

  uint16_t tmpUpdateTimeMs = m_minUpdateTimeMs;

  //
  // Determine the update time of the screen
  //
  switch (state)
  {
    case GameState::OutOfGame:
      {
        tmpUpdateTimeMs = m_durationMsIdleNoGame / m_numStepsIdleNoGame;
        break;
      }
    case GameState::StartGame:
      {
        tmpUpdateTimeMs = m_durationMsStart / m_numStepsStart;
        break;
      }
    case GameState::InGameIdle:
      {
        tmpUpdateTimeMs = m_durationMsIdleInGame / m_numStepsIdleInGame;
        break;
      }
    case GameState::InGameScored:
      {
        break;
      }
    case GameState::ReachedMaxScore:
      {
        tmpUpdateTimeMs = m_durationMsVictory / m_numStepsVictory;
        break;
      }
    case GameState::StopGame:
      {
        tmpUpdateTimeMs = m_durationMsStopGame / m_numStepsStopGame;
        break;
      }
  };

  m_updateTimeMs = tmpUpdateTimeMs;

  //
  // Update the screen
  //
  // The *_I version of this macro lets you channge the timer
  // with name animationTimer (this can be any name).
  // The default period is m_minUpdateTimeMs (just a variable or constant)
  EVERY_N_MILLISECONDS_I(animationTimer, m_minUpdateTimeMs)
  {
    switch (state)
    {
      case GameState::OutOfGame:
        {
          animationComplete = AnimationIdleNoGame();
          break;
        }
      case GameState::StartGame:
        {
          animationComplete = AnimationStart();
          break;
        }
      case GameState::InGameIdle:
        {
          animationComplete = AnimationIdleInGame();

          if (m_lastScorePlayer1 != m_currentScorePlayer1)
          {
            if (AnimationNewScore(m_currentScorePlayer1, 1))
            {
              m_lastScorePlayer1 = m_currentScorePlayer1;
            }
          }
          if (m_lastScorePlayer2 != m_currentScorePlayer2)
          {
            if (AnimationNewScore(m_currentScorePlayer2, 2))
            {
              m_lastScorePlayer2 = m_currentScorePlayer2;
            }
          }

          break;
        }
      case GameState::InGameScored:
        {
          // Handled by Scoreboard::UpdateScore(...)
          // since it is an overlay on AnimationIdleInGame()
          break;
        }
      case GameState::ReachedMaxScore:
        {
          animationComplete = AnimationVictory(m_winningPlayer);
          break;
        }
      case GameState::StopGame:
        {
          animationComplete = AnimationStopGame();
          break;
        }
    };

    animationTimer.setPeriod(m_updateTimeMs);
  }

  return animationComplete;
}

bool Scoreboard::SetPlayerCount(const uint8_t numPlayers)
{
  if (numPlayers > m_maxPlayers)
  {
    return false;
  }

  m_playerCount = numPlayers;
  return true;
}

uint8_t Scoreboard::GetPlayerCount()
{
  return m_playerCount;
}

bool Scoreboard::UpdateScore(uint32_t newScore, uint8_t player)
{
  if (player > m_playerCount)
  {
    return false;
  }

  switch (player)
  {
    case 1:
      {
        m_currentScorePlayer1 = newScore;
      }
    case 2:
      {
        m_currentScorePlayer2 = newScore;
      }
  };

  return true;
}

bool Scoreboard::ReachedMaxScore(uint8_t player)
{
  if (player < 1 || player > m_playerCount)
  {
    return false;
  }

  m_winningPlayer = player;
  return true;
}

//===============
// Private functions
//===============

bool Scoreboard::AnimationIdleNoGame()
{
  bool animationComplete = false;

  const uint8_t hueMatrixDelta = 64;
  const uint8_t columnHueDelta = ((float)hueMatrixDelta / m_matrixScreenSize.X);
  const uint8_t hueLedDelta = 2;

  m_currentSaturation = 255;
  m_currentValue = 150; // Brightness

  //
  // Set background
  //
  m_currentHue = m_curStepIdleNoGame * hueLedDelta;
  for (size_t c = 0; c < m_matrixScreenSize.X; c++)
  {
    m_currentHue += columnHueDelta;
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
      m_ledMatrix[index] = CHSV(m_currentHue, m_currentSaturation, m_currentValue);
    }
  }

  //
  // Set sprites
  //
  m_ballSpriteViewer->SetSpriteOnScreen();
  
  m_ballSpriteViewer->TranslateSprite({1, 0});
  if (m_ballSpriteViewer->GetPosition().X >= m_matrixScreenSize.X)
  {
    m_ballSpriteViewer->SetPosition({ -(m_ballSpriteViewer->GetSpriteSize()).X, 2});
  }
  //-----

  FastLED.show();
  if (++m_curStepIdleNoGame >= m_numStepsIdleNoGame)
  {
    animationComplete = true;
    m_curStepIdleNoGame = 0;
  }

  return animationComplete;
}

bool Scoreboard::AnimationStart()
{
  bool animationComplete = false;


  for (size_t c = 0; c < m_matrixScreenSize.X; c++)
  {
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
      m_ledMatrix[index] = CRGB::Black;
    }
  }

  //
  // Set sprites
  //
  if (m_curStepStart == 0)
  {
    for (size_t c = 0; c < m_matrixScreenSize.X; c++)
    {
      for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
      {
        size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
        m_ledMatrix[index] = CRGB::Red;
      }
    }
  }
  else if (m_curStepStart > 0 && m_curStepStart < 4)
  {
    if (m_curStepStart >= 1)
    {
      SpriteViewer ballOne = *m_ballSpriteViewer;
      ballOne.SetPriteSolidColor(CHSV(HSV_RAINDBOW_RED, 255, 255));
      ballOne.SetPosition({2, 2});
      ballOne.SetSpriteOnScreen();
    }

    if (m_curStepStart >= 2)
    {
      SpriteViewer ballTwo = *m_ballSpriteViewer;
      ballTwo.SetPriteSolidColor(CHSV(HSV_RAINDBOW_RED, 255, 255));
      ballTwo.SetPosition({13, 2});
      ballTwo.SetSpriteOnScreen();
    }

    if (m_curStepStart >= 3)
    {
      SpriteViewer ballThree = *m_ballSpriteViewer;
      ballThree.SetPriteSolidColor(CHSV(HSV_RAINDBOW_RED, 255, 255));
      ballThree.SetPosition({25, 2});
      ballThree.SetSpriteOnScreen();
    }
  }
  else if (m_curStepStart == 4)
  {
    for (size_t c = 0; c < m_matrixScreenSize.X; c++)
    {
      for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
      {
        size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
        m_ledMatrix[index] = CRGB::Green;
      }
    }
  }

  FastLED.show();
  if (++m_curStepStart == m_numStepsStart)
  {
    animationComplete = true;
    m_curStepStart = 0;
  }

  return animationComplete;
}

bool Scoreboard::AnimationIdleInGame()
{
  bool animationComplete = false;

  for (size_t c = 0; c < m_matrixScreenSize.X; c++)
  {
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
      m_ledMatrix[index] = CRGB::Pink;
    }
  }

  FastLED.show();
  if (++m_curStepIdleInGame == m_numStepsIdleInGame)
  {
    animationComplete = true;
    m_curStepIdleInGame = 0;
  }

  return animationComplete;
}

bool Scoreboard::AnimationNewScore(uint32_t newScore, uint8_t player)
{
  bool animationComplete = false;
  
  for (size_t c = 0; c < m_matrixScreenSize.X; c++)
  {
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
      m_ledMatrix[index] = CRGB::Orange;
    }
  }

  return animationComplete;
}

bool Scoreboard::AnimationVictory(uint8_t player)
{
  bool animationComplete = false;

  for (size_t c = 0; c < m_matrixScreenSize.X; c++)
  {
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
      m_ledMatrix[index] = CRGB::Blue;
    }
  }

  FastLED.show();
  if (++m_curStepVictory == m_numStepsVictory)
  {
    animationComplete = true;
    m_curStepVictory = 0;
  }

  return animationComplete;
}

bool Scoreboard::AnimationStopGame()
{
  bool animationComplete = false;

  for (size_t c = 0; c < m_matrixScreenSize.X; c++)
  {
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
      m_ledMatrix[index] = CRGB::Yellow;
    }
  }

  FastLED.show();
  if (++m_curStepStopGame == m_numStepsStopGame)
  {
    animationComplete = true;
    m_curStepStopGame = 0;
  }

  return animationComplete;
}

bool Scoreboard::ClearMatrix()
{
  bool animationComplete = false;
  for (size_t i = 0; i < m_numLeds; i++)
  {
    m_ledMatrix[i] = CRGB::Black;
  }
  FastLED.show();

  animationComplete = true;
  return animationComplete;
}
