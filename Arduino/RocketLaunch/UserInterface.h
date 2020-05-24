#pragma once

#include <Arduino.h>

class UserInterface
{
  public:
    UserInterface(const uint8_t playerCountSelectPin, const uint8_t gameModeSelectPin, const uint8_t startResetPin,
                  void (*startCallback)(const uint8_t numPlayers),
                  void (*resetCallback)(void));

    void update();

  private:
    // Functions
    const uint8_t getPlayerCountSelection();
    const uint8_t getGameModeSelection();

    // Callback function pointers
    void (*m_startCallback)(const uint8_t numPlayers, const uint8_t gameMode);
    void (*m_resetCallback)(void);
    
    // I/O pins
    const uint8_t m_playerCountSelectPin;
    const uint8_t m_gameModeSelectPin;
    const uint8_t m_startResetPin;

    // Button state helpers
    bool m_lastButtonState = HIGH;
    uint32_t m_btnChangeTimestampMs = 0;
    //  1> seconds: Start
    //  1< seconds: Reset
    const uint32_t m_startResetBtnPressThresholdMs = 1000; // 1 second
    bool m_sentReset = false;
};
