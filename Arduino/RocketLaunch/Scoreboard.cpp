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
  delete m_ballSprite;
  m_ballSprite = nullptr;
}

//===============
// Public functions
//===============

void Scoreboard::Update()
{
  if (m_doIdleAnimation)
  {
    // The *_I version of this macro lets you channge the timer
    // with name animationTimer (this can be any name).
    // The default period is m_maxUpdateTimeMs (just a variable or constant)
    EVERY_N_MILLISECONDS_I(animationTimer, m_maxUpdateTimeMs)
    {
      animationTimer.setPeriod(m_updateTimeMs);
      AnimationIdleNoGame();
    }
  }

  //Serial.println(GetFPS());
}

void Scoreboard::Start()
{
  m_doIdleAnimation = false;

  ClearMatrix();
  //AnimationStart();
  //AnimationIdleInGame();
}

void Scoreboard::Reset()
{
  m_currentRow = 0;
  m_currentColumn = 0;

  ClearMatrix();

  m_doIdleAnimation = true;
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

  AnimationNewScore(newScore, player);

  return true;
}

bool Scoreboard::ReachedMaxScore(uint8_t player)
{
  if (player > m_playerCount)
  {
    return false;
  }

  AnimationVictory(player);
  return true;
}

//===============
// Private functions
//===============

void Scoreboard::AnimationIdleNoGame()
{
  const uint8_t hueMatrixDelta = 64;
  const uint8_t columnHueDelta = ((float)hueMatrixDelta / m_matrixScreenSize.X);
  const uint8_t hueLedDelta = 2;

  const uint16_t animationSteps = 256 / hueLedDelta;
  static uint8_t currentStep = 0;

  const uint16_t tmpUpdateTimeMs = m_durationMsIdleNoGame / animationSteps;
  m_updateTimeMs = (tmpUpdateTimeMs < m_maxUpdateTimeMs) ? m_maxUpdateTimeMs : tmpUpdateTimeMs;

  m_currentSaturation = 255;
  m_currentValue = 150; // Brightness

  m_currentHue = currentStep * hueLedDelta;
  for (size_t c = 0; c < m_matrixScreenSize.X; c++)
  {
    m_currentHue += columnHueDelta;
    for (size_t r = 0; r < m_matrixScreenSize.Y; r++)
    {
      size_t index = MatrixUtil::MatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
      m_ledMatrix[index] = CHSV(m_currentHue, m_currentSaturation, m_currentValue);
    }
  }

  m_ballSprite->SetPosition(m_ballSpriteTopLeft);
  m_ballSprite->SetSpriteOnScreen();
  m_ballSpriteTopLeft.X++;
  if (m_ballSpriteTopLeft.X >= m_matrixScreenSize.X)
  {
    m_ballSpriteTopLeft.X = -m_ballSpriteSize.X;
  }
  //-----

  FastLED.show();
  if (++currentStep >= animationSteps)
  {
    currentStep = 0;
  }
}

void Scoreboard::AnimationStart()
{

}

void Scoreboard::AnimationIdleInGame()
{

}

void Scoreboard::AnimationNewScore(uint32_t newScore, uint8_t player)
{

}

void Scoreboard::AnimationVictory(uint8_t player)
{

}

void Scoreboard::ClearMatrix()
{
  for (size_t i = 0; i < m_numLeds; i++)
  {
    m_ledMatrix[i] = CRGB::Black;
  }
  FastLED.show();
}

/*
  void Scoreboard::ShowSprite2d(const CRGB* sprite, const bool* spriteMask, const XY& spriteSize, const XY& topLeftOrigin)
  {
  if (sprite == nullptr || spriteMask == nullptr)
  {
    return;
  }

  if(topLeftOrigin.X >= m_matrixScreenSize.X || topLeftOrigin.Y >= m_matrixScreenSize.Y)
  {
    // Nothing to be drawn.
    return;
  }

  XY topLeft = {};
  if(topLeftOrigin.X < 0)
  {
    topLeft.X = 0;
  }
  if(topLeftOrigin.Y < 0)
  {
    topLeft.Y = 0;
  }

  XY bottomRight = {topLeftOrigin.X + (spriteSize.X - 1), topLeftOrigin.Y + (spriteSize.Y - 1)};
  if(topLeftOrigin.X < 0)
  {
    bottomRight.X -= topLeftOrigin.X;
  }
  if(topLeftOrigin.Y < 0)
  {
    bottomRight.Y -= topLeftOrigin.Y;
  }

  if(bottomRight.X < 0 || bottomRight.Y < 0)
  {
    // Nothing to be drawn.
    return;
  }

  for (size_t c = 0; c < bottomRight.X; c++)
  {
    for (size_t r = 0; r < bottomRight.Y; r++)
    {
      size_t matrixIndex = MatrixUtil::MatrixToLinearIndex(c + topLeftOrigin.X, r + topLeftOrigin.Y, m_matrixScreenSize.X, m_matrixScreenSize.Y);
      size_t spriteIndex = MatrixUtil::MatrixToLinearIndex(c, r, spriteSize.X, spriteSize.Y);

      if (spriteMask[spriteIndex])
      {
        m_ledMatrix[matrixIndex] = sprite[spriteIndex];
      }
    }
  }
  }
*/
