//====================
//
// Dependecies:
//  - FastLED | V3.3.3 | https://github.com/FastLED/FastLED | Get it using the Arduino IDE "Sketch > Include Library > Manage Libraries > Search for FastLED (V 3.3.3)"
//
//====================

#include "Scoreboard.h"
#include "GameState.h"
#include "Player.h"
#include "SerialCom.h"
#include "MicroBitCommunication.h"

//----------
// Configuration pins
const uint8_t playerSelectPin = 4;
const uint8_t gameModePin = 5;
const uint8_t startResetPin = 6;
//----------

//----------
// Serial
const char startChar = '#';
const char stopChar = '%';
SerialCom mySerial(115200, startChar, stopChar);
//----------

//----------
// Micro:Bit communication
const uint8_t communicatioArduinoRxEnablePin = 2;
const uint8_t communicatioMicrobitRxSendEnablePin = 3;
MicroBitCommunication microBitCom(mySerial, communicatioArduinoRxEnablePin, communicatioMicrobitRxSendEnablePin);
uint8_t playerCount = 1;
uint8_t gameMode = 1;
//----------

//----------
// Players
const uint8_t maxPlayerCount = 2;
Player player1;
Player player2; // player2 my not be used
const Player* players[maxPlayerCount] = { &player1, &player2 };
uint8_t winningPlayer = 0;
//----------

//----------
// Scoreboard
Scoreboard scoreboard;
bool animationRoundComplete = false;
//----------

//----------
// Points
struct ScoreInfo
{
  bool newScoreFlag = false;
  uint8_t player = 0;
  uint8_t points = 0;
};

ScoreInfo receivedScoreInfo = {};
const uint32_t maxScore = 120;

const unsigned long maxTimeInScoreStateMs = 10000; // 10 seconds
unsigned long startTimeOfMaxScoreState = 0;
//----------

//----------
// Start/Reset
bool lastButtonState = HIGH;
uint32_t btnChangeTimestampMs = 0;
//  1> seconds: Start
//  1< seconds: Reset
const uint32_t startResetBtnPressThresholdMs = 1000; // 1 second
bool doStart = false;
bool doReset = false;
bool didReset = false;
//----------

//----------
// Confetti cannons
const uint8_t cannonPin = 2;
//----------

//----------
// Game state
GameState previousState = GameState::OutOfGame;
GameState currentState = GameState::OutOfGame;
//----------

//----------
// General functions
void UpdateGameState();
void StartResetButtonPressed();
void InitializeGame();
void StartGame();
void StopGame();
void fireConfettiCannons();
void TargetHitCallback(const uint8_t player, const uint8_t points);
//----------

void setup()
{
  // Configuration pins
  pinMode(startResetPin, INPUT_PULLUP); // https://www.arduino.cc/en/Tutorial/InputPullupSerial
  pinMode(playerSelectPin, INPUT);
  pinMode(gameModePin, INPUT);

  pinMode(cannonPin, OUTPUT);
  digitalWrite(cannonPin, LOW);

  mySerial.Open();
  microBitCom.OnTargetHit(&TargetHitCallback);
  microBitCom.Start();
  scoreboard.Reset();
}

void loop()
{
  // The FastLED library (used in Scoreboard)
  // disables the interrupts which can
  // cause received serial bytes to be lost.
  //
  // To avoid losing bytes from the Micro:Bit, the Micro:Bit is signalled to
  // wait with sending bytes while FastLED is writing data
  // to the LEDs

  microBitCom.Update(); // Read data from the receive buffer
  StartResetButtonPoll();

  // Update the game state based on
  // the received bytes from the Micro:Bit and the button press
  UpdateGameState();

  microBitCom.DisableCommunication();
  delayMicroseconds(200); // Wait to make sure that last byte(s) is stored in the receive buffer

  animationRoundComplete = scoreboard.Update(currentState); // Perform an animation step on the LED matrix

  microBitCom.EnableCommunication();
  delay(5); // Time to receive data
}

void UpdateGameState()
{
  switch (currentState)
  {
    case GameState::OutOfGame:
      {
        // A result from StartResetButtonPoll()
        if (doStart)
        {
          previousState = currentState;
          currentState = GameState::StartGame;
        }

        break;
      }
    case GameState::StartGame:
      {
        if (doStart)
        {
          InitializeGame();
          StartGame();
          delay(1); // Give the Micro:Bit some time to set its communication enable pin

          doStart = false;
        }

        if (animationRoundComplete)
        {
          previousState = currentState;
          currentState = GameState::InGameIdle;
        }

        break;
      }
    case GameState::InGameIdle:
      {
        // A result from StartResetButtonPoll()
        if (doReset)
        {
          previousState = currentState;
          currentState = GameState::StopGame;
        }

        // Updated in TargetHitCallback()
        if (receivedScoreInfo.newScoreFlag)
        {
          previousState = currentState;
          currentState = GameState::InGameScored;
        }

        break;
      }
    case GameState::InGameScored:
      {
        receivedScoreInfo.newScoreFlag = false; // Reset the flag

        uint8_t player = receivedScoreInfo.player;

        if ((player >= 1) && (player <= maxPlayerCount))
        {
          uint32_t newScore = players[receivedScoreInfo.player - 1]->AddPoints(receivedScoreInfo.points);

          if (newScore >= maxScore)
          {
            winningPlayer = player;               // Used in the GameState::ReachedMaxScore state

            scoreboard.ReachedMaxScore(winningPlayer);
            fireConfettiCannons();

            previousState = currentState;
            currentState = GameState::ReachedMaxScore;
          }
          else
          {
            scoreboard.UpdateScore(newScore, player);

            previousState = currentState;
            currentState = GameState::InGameIdle;
          }
        }

        break;
      }
    case GameState::ReachedMaxScore:
      {
        if (doReset || animationRoundComplete)
        {
          previousState = currentState;
          currentState = GameState::StopGame;

          // Make sure that it is true even if
          // GameState::StopGame was set because
          // animation finished (animationRoundComplete)
          doReset = true;
        }

        break;
      }
    case GameState::StopGame:
      {
        if (doReset)
        {
          StopGame();
          doReset = false;
          didReset = true;
        }

        if (animationRoundComplete)
        {
          previousState = currentState;
          currentState = GameState::OutOfGame;
        }

        break;
      }
  };
}

void StartResetButtonPoll()
{
  const bool buttonState = digitalRead(startResetPin);
  const long currentMillis = millis();

  // Button is pressed down but not yet released
  if ((lastButtonState == HIGH) && (buttonState == LOW))
  {
    btnChangeTimestampMs = currentMillis;

    doStart = false;
    doReset = false;
    didReset = false;
  }
  // Button is still pressed.
  // Check if it is pressed for longer than the reset time threshold
  // This approach makes sure that you don't have to release the button in order to reset the system
  else if ((lastButtonState == LOW) && (buttonState == LOW) && (didReset == false))
  {
    if ((currentMillis - btnChangeTimestampMs) > startResetBtnPressThresholdMs)
    {
      doStart = false;
      doReset = true;
    }
  }
  // Button was released
  // Check if the button was released withing the start time threshold
  else if ((lastButtonState == LOW) && (buttonState == HIGH))
  {
    if ((currentMillis - btnChangeTimestampMs) <= startResetBtnPressThresholdMs)
    {
      doStart = true;
      doReset = false;
    }
  }

  lastButtonState = buttonState;
}

void InitializeGame()
{
  // reading a 0 -> 1 player
  // reading a 1 -> 2 players
  playerCount = (digitalRead(playerSelectPin) == 0) ? 1 : 2;
  gameMode = (digitalRead(gameModePin) == 0) ? 1 : 2;

  scoreboard.SetPlayerCount(playerCount);
  microBitCom.GiveNumPlayers(playerCount);
  //microBitCom.GiveGameMode();
}

void StartGame()
{
  microBitCom.SendStart();
}

void StopGame()
{
  microBitCom.SendQuit();
  player1.Reset();
  player2.Reset();
  scoreboard.Reset();
}

void fireConfettiCannons()
{
  digitalWrite(cannonPin, HIGH);
  delay(500);
  digitalWrite(cannonPin, LOW);
}

void TargetHitCallback(const uint8_t player, const uint8_t points)
{
  receivedScoreInfo.newScoreFlag = true;
  receivedScoreInfo.player = player;
  receivedScoreInfo.points = points;
}
