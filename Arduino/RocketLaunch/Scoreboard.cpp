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

  delete m_character_R_SpriteViewer;
  m_character_R_SpriteViewer = nullptr;
}

//===============
// Public functions
//===============

void Scoreboard::Reset()
{
  m_currentRow = 0;
  m_currentColumn = 0;

  ClearMatrix();

  m_doIdleAnimation = true;
}

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
  m_doIdleAnimation = false;

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
      size_t index = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_matrixScreenSize.X, m_matrixScreenSize.Y);
      m_ledMatrix[index] = CHSV(m_currentHue, m_currentSaturation, m_currentValue);
    }
  }

  m_ballSpriteViewer->SetPosition(m_ballSpriteTopLeft);
  m_ballSpriteViewer->SetSpriteOnScreen();
  m_ballSpriteTopLeft.X++;
  if (m_ballSpriteTopLeft.X >= m_matrixScreenSize.X)
  {
    m_ballSpriteTopLeft.X = -(m_ballSpriteViewer->GetSpriteSize()).X;
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
