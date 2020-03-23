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

  for(int i = 0; i < sizeof(m_numberSprites)/sizeof(m_numberSprites[0]); i++)
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

  // The *_I version of this macro lets you channge the timer
  // with name animationTimer (this can be any name).
  // The default period is m_minUpdateTimeMs (just a variable or constant)
  EVERY_N_MILLISECONDS_I(animationTimer, m_minUpdateTimeMs)
  {
    animationTimer.setPeriod(m_updateTimeMs);

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

void Scoreboard::Start()
{
  ClearMatrix();
  AnimationStart();
  AnimationIdleInGame();
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

  const uint16_t animationSteps = 256 / hueLedDelta;
  static uint8_t currentStep = 0;

  const uint16_t tmpUpdateTimeMs = m_durationMsIdleNoGame / animationSteps;
  m_updateTimeMs = (tmpUpdateTimeMs < m_minUpdateTimeMs) ? m_minUpdateTimeMs : tmpUpdateTimeMs;

  m_currentSaturation = 255;
  m_currentValue = 150; // Brightness

  m_currentHue = currentStep * hueLedDelta;
  for (size_t c = 0; c < m_matrixScreenSize.X; c++)
  {
    m_currentHue += columnHueDelta;
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
      m_ledMatrix[index] = CHSV(m_currentHue, m_currentSaturation, m_currentValue);
    }
  }

  m_ballSpriteViewer->SetPosition({ -(m_ballSpriteViewer->GetSpriteSize()).X, 2});
  m_ballSpriteViewer->SetSpriteOnScreen();
  m_ballSpriteViewer->TranslateSprite({1, 0});
  if (m_ballSpriteViewer->GetPosition().X >= m_matrixScreenSize.X)
  {
    m_ballSpriteViewer->SetPosition({ -(m_ballSpriteViewer->GetSpriteSize()).X, 2});
  }
  //-----

  FastLED.show();
  if (++currentStep >= animationSteps)
  {
    animationComplete = true;
    currentStep = 0;
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
      m_ledMatrix[index] = CHSV(HSV_RAINDBOW_ORANGE, 200, 100);
    }
  }

  m_numberSprites[0]->SetPosition({0, 1});
  m_numberSprites[0]->SetSpriteOnScreen();

  m_numberSprites[1]->SetPosition({m_numberSprites[0]->GetSpriteSize().X, 1});
  m_numberSprites[1]->SetSpriteOnScreen();

  m_numberSprites[2]->SetPosition({m_numberSprites[1]->GetSpriteSize().X, 1});
  m_numberSprites[2]->SetSpriteOnScreen();

  FastLED.show();

  return animationComplete;
}

bool Scoreboard::AnimationIdleInGame()
{
  bool animationComplete = false;

  
  
  return animationComplete;
}

bool Scoreboard::AnimationNewScore(uint32_t newScore, uint8_t player)
{
  bool animationComplete = false;
  return animationComplete;
}

bool Scoreboard::AnimationVictory(uint8_t player)
{
  bool animationComplete = false;
  return animationComplete;
}

bool Scoreboard::AnimationStopGame()
{
  bool animationComplete = false;
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
