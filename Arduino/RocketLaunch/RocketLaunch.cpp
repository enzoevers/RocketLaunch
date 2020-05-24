#include "RocketLaunch.h"

#include "Scoreboard.h"
#include "GameStateManager.h"
#include "SerialCom.h"
#include "MicroBitCommunication.h"
#include "UserInterface.h"
#include <Arduino.h>

//----------
// Serial
const char startChar = '#';
const char stopChar = '%';

SerialCom mySerial(115200, startChar, stopChar);
//----------

//----------
// Micro:Bit communication
void targetHitEventCallback(const uint8_t player, const uint8_t points);
const uint8_t communicatioArduinoRxEnablePin = 2;
const uint8_t communicatioMicrobitRxSendEnablePin = 3;

static MicroBitCommunication microBitCom(mySerial, communicatioArduinoRxEnablePin, communicatioMicrobitRxSendEnablePin,
                                         targetHitEventCallback);
//----------

//----------
// Scoreboard
void scoreboardAnimationCompleteEventCallback();

Scoreboard scoreboard(scoreboardAnimationCompleteEventCallback);
//----------

//----------
// Game state
void stateChangeCallback_startGame(const uint8_t numPlayers, const uint8_t gameMode);
void stateChangeCallback_maxScore(const uint8_t winningPlayer);
void stateChangeCallback_stopGame();

GameStateManager gameStateManager(stateChangeCallback_startGame,
                                  stateChangeCallback_maxScore,
                                  stateChangeCallback_stopGame);
//----------

//----------
// User interface
const uint8_t playerSelectPin = 4;
const uint8_t gameModePin = 5;
const uint8_t startResetPin = 6;
void startEventCallback(const uint8_t numPlayers, const uint8_t gameMode);
void resetEventCallback();

UserInterface userInterface(playerSelectPin, gameModePin, startResetPin,
                            startEventCallback, resetEventCallback);
//----------

//----------
// Confetti cannons
const uint8_t cannonPin = 2;
void fireConfettiCannons();
//----------

//==========
// Public namespace functions
//==========
void RocketLaunch::start()
{
  pinMode(cannonPin, OUTPUT);
  digitalWrite(cannonPin, LOW);

  mySerial.open();
  microBitCom.start();
  scoreboard.reset();
}

void RocketLaunch::run()
{
  // The FastLED library (used in Scoreboard)
  // disables the interrupts which can
  // cause received serial bytes to be lost.
  //
  // To avoid losing bytes from the Micro:Bit, the Micro:Bit is signalled to
  // wait with sending bytes while FastLED is writing data
  // to the LEDs

  microBitCom.update(); // Read data from the receive buffer
  userInterface.update();

  // Update the game state based on
  // the received bytes from the Micro:Bit and the button press
  gameStateManager.update();

  microBitCom.disableCommunication();
  delayMicroseconds(200); // Wait to make sure that last byte(s) is stored in the receive buffer

  scoreboard.update(gameStateManager.getCurrentState()); // Perform an animation step on the LED matrix

  microBitCom.enableCommunication();
  delay(5); // Time to receive data
}

//==========
// Private functions
//==========

//----------
// Incoming external events
void startEventCallback(const uint8_t numPlayers, const uint8_t gameMode)
{
  gameStateManager.notify_startGame(numPlayers, gameMode);
}

void resetEventCallback()
{
  gameStateManager.notify_stopGame();
}

void targetHitEventCallback(const uint8_t player, const uint8_t points)
{
  uint32_t newScore = scoreboard.updateScore(points, player);
  gameStateManager.notify_playerScored(player, newScore);
}

void scoreboardAnimationCompleteEventCallback()
{
  gameStateManager.notify_animationComplete();
}
//----------

//----------
// StateChange events
void stateChangeCallback_startGame(const uint8_t numPlayers, const uint8_t gameMode)
{
  scoreboard.setPlayerCount(numPlayers);
  microBitCom.giveNumPlayers(numPlayers);
  //microBitCom.GiveGameMode();

  microBitCom.sendStart();
}

void stateChangeCallback_maxScore(const uint8_t winningPlayer)
{
  scoreboard.reachedMaxScore(winningPlayer);
  fireConfettiCannons();
}

void stateChangeCallback_stopGame()
{
  microBitCom.sendQuit();
  scoreboard.reset();
}
//----------

void fireConfettiCannons()
{
  digitalWrite(cannonPin, HIGH);
  delay(500);
  digitalWrite(cannonPin, LOW);
}
