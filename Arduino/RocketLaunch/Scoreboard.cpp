#include "Scoreboard.h"

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

  m_playerCount = 1;
  m_winningPlayer = 1;

  m_lastScorePlayer1 = 0;
  m_lastScorePlayer2 = 0;

  m_currentScorePlayer1 = 0;
  m_currentScorePlayer2 = 0;

  m_curStepIdleNoGame = 0;
  m_curStepStart = 0;
  m_curStepIdleInGame = 0;
  m_curStepNewScore = 0;
  m_curStepVictory = 0;
  m_curStepStopGame = 0;


  //ClearMatrix();
}

bool Scoreboard::Update(GameState& state)
{
  bool animationComplete = false;

  if (m_prevState != state)
  {
    m_prevState = state;
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
    m_updateScreenNow = true;
  }

  //
  // Update the screen
  //
  if (m_updateScreenNow || (millis() - m_lastMillisScreenUpdate) > m_updateTimeMs)
  {
    m_lastMillisScreenUpdate = millis();
    m_updateScreenNow = false;

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
            m_lastScorePlayer1 = m_currentScorePlayer1;
          }
          if (m_lastScorePlayer2 != m_currentScorePlayer2)
          {
            m_lastScorePlayer2 = m_currentScorePlayer2;
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
        break;
      }
    case 2:
      {
        m_currentScorePlayer2 = newScore;
        break;
      }
  };

  m_updateScreenNow = true;

  return true;
}

bool Scoreboard::ReachedMaxScore(uint8_t player)
{
  if (player < 1 || player > m_playerCount)
  {
    return false;
  }

  m_winningPlayer = player;

  m_updateScreenNow = true;
  return true;
}

//===============
// Private functions
//===============

bool Scoreboard::AnimationIdleNoGame()
{
  bool animationComplete = false;

  if (m_curStepIdleNoGame >= m_numStepsIdleNoGame)
  {
    animationComplete = true;
    m_curStepIdleNoGame = 0;
  }

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

  FastLED.show();
  m_curStepIdleNoGame++;

  return animationComplete;
}

bool Scoreboard::AnimationStart()
{
  bool animationComplete = false;

  if (m_curStepStart == m_numStepsStart)
  {
    animationComplete = true;
    m_curStepStart = 0;
  }

  //
  // Set background
  //
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
  m_curStepStart++;

  return animationComplete;
}

bool Scoreboard::AnimationIdleInGame()
{
  bool animationComplete = false;

  if (m_curStepIdleInGame == m_numStepsIdleInGame)
  {
    animationComplete = true;
    m_curStepIdleInGame = 0;
  }

  switch (m_playerCount)
  {
    case 1:
      {
        AnimationIdleInGame_SinglePlayer();
        break;
      }
    case 2:
      {
        AnimationIdleInGame_DualPlayer();
        break;
      }
  };

  FastLED.show();
  m_curStepIdleInGame++;

  return animationComplete;
}

void Scoreboard::AnimationIdleInGame_SinglePlayer()
{
  //
  // Set background
  //
  for (size_t c = 0; c < m_matrixScreenSize.X; c++)
  {
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);

      CRGB color;
      if (c == 0 || c == (m_matrixScreenSize.X - 1)
          || r == 0 || r == (m_matrixScreenSize.Y - 1))
      {
        color = CHSV(m_huePlayer1, 255, 80);
      }
      else
      {
        color = CRGB::Black;
      }
      m_ledMatrix[index] = color;
    }
  }

  //
  // Set sprites
  //
  char scoreStringBuf[4]; // Max score is < 1000 which means 3 characters + \0 at max
  const uint8_t numChars = sprintf(scoreStringBuf, "%d", m_currentScorePlayer1);

  // All numeric sprites in the SpriteCollection namespace are 3 pixels wide
  // and in front of each number a one pixel spacing is given. This will result in
  // an length of a even value which makes dividing up the free space easier
  const uint8_t spriteWidth = 1 + 3; // 1 spacing pixel; 3 sprite pixels
  const uint8_t totalScoreWidth = numChars * spriteWidth;
  MatrixUtil::XY startIndexSprite =
  {
    ((m_matrixScreenSize.X - totalScoreWidth) / 2) - 1, // -1 to account for the index starting at 0
    0
  };

  AnimationIdleInGame_WritePoints(scoreStringBuf, numChars, CHSV(m_huePlayer1, 10, 150), startIndexSprite);
}

void Scoreboard::AnimationIdleInGame_DualPlayer()
{
  //
  // Right side: player 1
  //

  //
  // Set Background
  //
  for (size_t c = 0; c < m_matrixScreenSize.X / 2; c++)
  {
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);

      CRGB color;
      if (c == 0 || c == (m_matrixScreenSize.X / 2 - 1)
          || r == 0 || r == (m_matrixScreenSize.Y - 1))
      {
        color = CHSV(m_huePlayer1, 255, 80);
      }
      else
      {
        color = CRGB::Black;
      }
      m_ledMatrix[index] = color;
    }
  }

  //
  // Set sprites
  //
  char scoreStringBuf[4]; // Max score is < 1000 which means 3 characters + \0 at max
  uint8_t numChars = sprintf(scoreStringBuf, "%d", m_currentScorePlayer1);

  // All numeric sprites in the SpriteCollection namespace are 3 pixels wide
  // and in front of each number a one pixel spacing is given. This will result in
  // an length of a even value which makes dividing up the free space easier
  const uint8_t spriteWidth = 1 + 3; // 1 spacing pixel; 3 sprite pixels
  uint8_t totalScoreWidth = numChars * spriteWidth;
  MatrixUtil::XY startIndexSprite =
  {
    ((m_matrixScreenSize.X / 2 - totalScoreWidth) / 2) - 1, // -1 to account for the index starting at 0
    0
  };

  AnimationIdleInGame_WritePoints(scoreStringBuf, numChars, CHSV(m_huePlayer1, 10, 150), startIndexSprite);

  //
  // Left side: player 2
  //

  //
  // Set Background
  //
  for (size_t c = m_matrixScreenSize.X / 2; c < m_matrixScreenSize.X; c++)
  {
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);

      CRGB color;
      if (c == m_matrixScreenSize.X / 2 || c == (m_matrixScreenSize.X - 1)
          || r == 0 || r == (m_matrixScreenSize.Y - 1))
      {
        color = CHSV(m_huePlayer2, 255, 80);
      }
      else
      {
        color = CRGB::Black;
      }
      m_ledMatrix[index] = color;
    }
  }

  //
  // Set sprites
  //
  numChars = sprintf(scoreStringBuf, "%d", m_currentScorePlayer2);

  totalScoreWidth = numChars * spriteWidth;
  startIndexSprite =
  {
    (((m_matrixScreenSize.X / 2 - totalScoreWidth) / 2) + m_matrixScreenSize.X / 2) - 1, // -1 to account for the index starting at 0
    0
  };

  AnimationIdleInGame_WritePoints(scoreStringBuf, numChars, CHSV(m_huePlayer2, 10, 150), startIndexSprite);
}

void Scoreboard::AnimationIdleInGame_WritePoints(char* scoreStringBuf, uint8_t numChars, CHSV color, MatrixUtil::XY startIndexSprite)
{
  const uint8_t verticalSpacingFromBottom = 1;

  // For each number is the value select the
  // correct sprite, give it a position, and set
  // the sprite data on the screen.
  for (int i = 0; i < numChars; i++)
  {
    const uint8_t asciiValueStart = 48; // http://www.asciitable.com/
    uint8_t value = scoreStringBuf[i] - asciiValueStart;
    if (value < 0 || value > 9)
    {
      value = 0; // The default value;
    }

    // The sprite object is temporary because once the data
    // of the sprite is written to the matrix (with SetSpriteOnScreen())
    // the sprite object isn't used anymore
    SpriteViewer tmpSprite = *m_numberSprites[value];

    startIndexSprite.X += 1; // One spacing pixel in front of each character
    if (i > 0)
    {
      startIndexSprite.X += tmpSprite.GetSpriteSize().X;
    }
    startIndexSprite.Y = m_matrixScreenSize.Y - verticalSpacingFromBottom - tmpSprite.GetSpriteSize().Y - 1;

    tmpSprite.SetPosition(startIndexSprite);
    tmpSprite.SetPriteSolidColor(color);
    tmpSprite.SetSpriteOnScreen();
  }
}

bool Scoreboard::AnimationNewScore(uint32_t newScore, uint8_t player)
{
  bool animationComplete = false;

  animationComplete = true;

  return animationComplete;
}

bool Scoreboard::AnimationVictory(uint8_t player)
{
  bool animationComplete = false;

  if (m_curStepVictory == m_numStepsVictory)
  {
    animationComplete = true;
    m_curStepVictory = 0;
  }

  for (size_t c = 0; c < m_matrixScreenSize.X; c++)
  {
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);

      uint8_t curHue;

      switch (player)
      {
        case 1: {
            curHue = m_huePlayer1;
            break;
          }
        case 2: {
            curHue = m_huePlayer2;
            break;
          }
      };

      m_ledMatrix[index] = CHSV(curHue, 255, 80);
    }
  }

  FastLED.show();
  m_curStepVictory++;

  return animationComplete;
}

bool Scoreboard::AnimationStopGame()
{
  bool animationComplete = false;

  if (m_curStepStopGame == m_numStepsStopGame)
  {
    animationComplete = true;
    m_curStepStopGame = 0;
  }

  for (size_t c = 0; c < m_matrixScreenSize.X; c++)
  {
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
      if ((
            (c + r) <= m_curStepStopGame || // Left side
            ((m_matrixScreenSize.X - 1) - (c - r)) <= m_curStepStopGame // Right side
          ) && r <= m_curStepStopGame)
      {
        m_ledMatrix[index] = CRGB::Black;
      }
    }
  }

  FastLED.show();
  m_curStepStopGame++;

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
