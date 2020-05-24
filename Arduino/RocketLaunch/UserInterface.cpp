#include "UserInterface.h"

UserInterface::UserInterface(const uint8_t playerCountSelectPin, const uint8_t gameModeSelectPin, const uint8_t startResetPin,
                             void (*startCallback)(const uint8_t numPlayers),
                             void (*resetCallback)(void))
: m_playerCountSelectPin(playerCountSelectPin),
  m_gameModeSelectPin(gameModeSelectPin),
  m_startResetPin(startResetPin),
  m_startCallback(startCallback),
  m_resetCallback(resetCallback)
  
{
  pinMode(m_playerCountSelectPin, INPUT);
  pinMode(m_gameModeSelectPin, INPUT);
  pinMode(m_startResetPin, INPUT_PULLUP); // https://www.arduino.cc/en/Tutorial/InputPullupSerial
}

//==========
// Public
//==========
void UserInterface::update()
{
  const bool buttonState = digitalRead(m_startResetPin);
  const long currentMillis = millis();

  // Button is pressed down but not yet released
  if ((m_lastButtonState == HIGH) && (buttonState == LOW))
  {
    m_btnChangeTimestampMs = currentMillis;
  }
  // Button is still pressed.
  // Check if it is pressed for longer than the reset time threshold
  // This approach makes sure that you don't have to release the button in order to reset the system
  else if ((m_lastButtonState == LOW) && (buttonState == LOW))
  {
    if ((currentMillis - m_btnChangeTimestampMs) > m_startResetBtnPressThresholdMs)
    {
      m_resetCallback();
    }
  }
  // Button was released
  // Check if the button was released withing the start time threshold
  else if ((m_lastButtonState == LOW) && (buttonState == HIGH))
  {
    if ((currentMillis - m_btnChangeTimestampMs) <= m_startResetBtnPressThresholdMs)
    {
      m_startCallback(getPlayerCountSelection(), getGameModeSelection());
    }
  }

  m_lastButtonState = buttonState;
}

//==========
// Private
//==========
const uint8_t UserInterface::getPlayerCountSelection()
{
  return (digitalRead(m_playerCountSelectPin) == 0) ? 1 : 2;
}

const uint8_t UserInterface::getGameModeSelection()
{
  return (digitalRead(m_gameModeSelectPin) == 0) ? 1 : 2;
}
