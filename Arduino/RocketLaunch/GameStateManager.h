#pragma once

#include <stdint.h>

enum class GameState
{
  OutOfGame,
  StartGame,
  InGameIdle,
  ReachedMaxScore,
  StopGame
};

class GameStateManager
{
  public:
    GameStateManager( void (*stateChangeCallback_startGame)(const uint8_t numPlayers, const uint8_t gameMode),
                      void (*stateChangeCallback_maxScore)(const uint8_t winningPlayer),
                      void (*stateChangeCallback_stopGame)(void));

    void update();
    GameState getCurrentState();

    // The notify_* functions are meant to be called by
    // a central piece of software which reads input events
    // from several sources and passes them on to the this class.
    //
    // The goal of this setup is to improve abstraction.
    void notify_startGame(const uint8_t numPlayers, const uint8_t gameMode);
    void notify_stopGame();
    void notify_playerScored(const uint8_t player, const uint8_t newScore);
    void notify_animationComplete();

  private:
    GameState m_previousState = GameState::OutOfGame;
    GameState m_currentState = GameState::OutOfGame;
    
    const uint32_t m_maxScore = 120;
    uint8_t m_numPlayers = 1;
    uint8_t m_gameMode = 1;

    void (*m_stateChangeCallback_startGame)(const uint8_t numPlayers, const uint8_t gameMode);
    void (*m_stateChangeCallback_maxScore)(const uint8_t winningPlayer);
    void (*m_stateChangeCallback_stopGame)(void);

    bool m_doStart = false;
    bool m_doReset = false;
    bool m_animationComplete = false;

    struct ScoreInfo
    {
      bool newScoreFlag = false;
      uint8_t player = 0;
      uint8_t newScore = 0;
    };
    ScoreInfo m_receivedScoreInfo = {};
};
