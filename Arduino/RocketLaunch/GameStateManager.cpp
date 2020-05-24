#include "GameStateManager.h"

#include <Arduino.h> // For the delay() function

GameStateManager::GameStateManager(void (*stateChangeCallback_startGame)(const uint8_t numPlayers, const uint8_t gameMode),
                                   void (*stateChangeCallback_maxScore)(const uint8_t winningPlayer),
                                   void (*stateChangeCallback_stopGame)(void))
    : m_stateChangeCallback_startGame(stateChangeCallback_startGame),
      m_stateChangeCallback_maxScore(stateChangeCallback_maxScore),
      m_stateChangeCallback_stopGame(stateChangeCallback_stopGame)
{
}

//==========
// Public
//==========
void GameStateManager::update()
{
  switch (m_currentState)
  {
  case GameState::OutOfGame:
  {
    // exit
    if (m_doStart)
    {
      m_previousState = m_currentState;
      m_currentState = GameState::StartGame;
    }

    break;
  }
  case GameState::StartGame:
  {
    // entry
    if (m_doStart)
    {
      m_stateChangeCallback_startGame(m_numPlayers, m_gameMode);
      delay(1); // Give the Micro:Bit some time to set its communication enable pin

      m_doStart = false;
    }

    // exit
    if (m_animationComplete)
    {
      m_previousState = m_currentState;
      m_currentState = GameState::InGameIdle;
      m_animationComplete = false;
    }

    break;
  }
  case GameState::InGameIdle:
  {
    // entry
    if (m_doReset)
    {
      m_previousState = m_currentState;
      m_currentState = GameState::StopGame;
    }

    // continuous
    if (m_receivedScoreInfo.newScoreFlag)
    {
      m_receivedScoreInfo.newScoreFlag = false; // Reset the flag

      uint8_t player = m_receivedScoreInfo.player;
      uint32_t newScore = m_receivedScoreInfo.newScore;

      // exit
      if (newScore >= m_maxScore)
      {
        m_stateChangeCallback_maxScore(player);

        m_previousState = m_currentState;
        m_currentState = GameState::ReachedMaxScore;
      }
    }

    break;
  }
  case GameState::ReachedMaxScore:
  {
    // exit
    if (m_doReset || m_animationComplete)
    {
      m_previousState = m_currentState;
      m_currentState = GameState::StopGame;
      m_animationComplete = false;

      // Settings it to true makes sure that the entry in
      // GameState::StopGame is performed
      m_doReset = true;
    }

    break;
  }
  case GameState::StopGame:
  {
    // entry
    if (m_doReset)
    {
      m_stateChangeCallback_stopGame();
      m_doReset = false;
    }

    // exit
    if (m_animationComplete)
    {
      m_previousState = m_currentState;
      m_currentState = GameState::OutOfGame;
      m_animationComplete = false;
    }

    break;
  }
  };

  m_animationComplete = false; // Resest the flag when not used in a state
}

GameState GameStateManager::getCurrentState()
{
  return m_currentState;
}

void GameStateManager::notify_startGame(const uint8_t numPlayers, const uint8_t gameMode)
{
  m_numPlayers = numPlayers;
  m_gameMode = gameMode;
  m_doStart = true;
}

void GameStateManager::notify_stopGame()
{
  m_doReset = true;
}

void GameStateManager::notify_playerScored(const uint8_t player, const uint8_t newScore)
{
  m_receivedScoreInfo.newScoreFlag = true;
  m_receivedScoreInfo.player = player;
  m_receivedScoreInfo.newScore = newScore;
}

void GameStateManager::notify_animationComplete()
{
  m_animationComplete = true;
}
