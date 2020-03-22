//====================
//
// Dependecies:
//  - FastLED | V3.3.3 | https://github.com/FastLED/FastLED | Get it using the Arduino IDE "Sketch > Include Library > Manage Libraries > Search for FastLED (V 3.3.3)"
//
//====================

#include "Scoreboard.h"
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
// Scoreboard
Scoreboard scoreboard;
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
// Points
struct ScoreInfo
{
  bool newScoreFlag = false;
  uint8_t player = 0;
  uint8_t points = 0;
};

ScoreInfo receivedScoreInfo = {};
const uint32_t maxScore = 100;
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
enum class GameState
{
  OutOfGame,
  StartGame,
  InGameIdle,
  InGameScored,
  ReachedMaxScore,
  StopGame
};

GameState previousState = GameState::OutOfGame;
GameState currentState = GameState::OutOfGame;
//----------

//----------
// General functions
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
  microBitCom.Update();

  // The FastLED library (used in Scoreboard)
  // disables the interrupts which can
  // cause received serial bytes to be lost.
  //
  // To avoid lost bytes the Micro:Bit is signalled to
  // wait with sending bytes while FastLED is writing data
  // to the LEDs
  microBitCom.DisableCommunication();
  delayMicroseconds(200); // Wait to make sure that last byte is received
  scoreboard.Update();
  microBitCom.EnableCommunication();
  delay(5); // Time to receive data

  StartResetButtonPoll();

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
        InitializeGame();
        delay(1); // Give the Micro:Bit some time to set its communication enable pin

        // TODO: Do startup animation on scoreboard

        StartGame();
        doStart = false;

        previousState = currentState;
        currentState = GameState::InGameIdle;

        break;
      }
    case GameState::InGameIdle:
      {
        if (previousState == GameState::StartGame)
        {
          // TODO: Start InGameIdle animation
        }
        else if (previousState == GameState::InGameScored)
        {
          // TODO: Continue InGameIdle animation
        }
        
        // A result from StartResetButtonPoll()
        if (doReset)
        {
          previousState = currentState;
          currentState = GameState::StopGame;
        }

        // Updated in TargetHitCallback()
        if (receivedScoreInfo.newScoreFlag)
        {
          receivedScoreInfo.newScoreFlag = false; // Reset the flag

          previousState = currentState;
          currentState = GameState::InGameScored;
        }

        break;
      }
    case GameState::InGameScored:
      {
        uint8_t player = receivedScoreInfo.player;

        if ((player >= 1) && (player <= maxPlayerCount))
        {
          uint32_t newScore = players[receivedScoreInfo.player - 1]->AddPoints(receivedScoreInfo.points);

          if (newScore >= maxScore)
          {
            winningPlayer = player;
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
        scoreboard.ReachedMaxScore(winningPlayer);
        fireConfettiCannons();

        previousState = currentState;
        currentState = GameState::StopGame;

        break;
      }
    case GameState::StopGame:
      {
        StopGame();
        doReset = false;
        didReset = true;

        previousState = currentState;
        currentState = GameState::OutOfGame;

        break;
      }
  };
}

void StartResetButtonPoll()
{
  const bool buttonState = digitalRead(startResetPin);
  const long currentMillis = millis();

  if ((lastButtonState != LOW) && (buttonState == LOW))
  {
    // Button was pressed
    btnChangeTimestampMs = currentMillis;

    didReset = false;
  }
  else if ((lastButtonState == LOW) && (buttonState == LOW) && (didReset == false))
  {
    if ((currentMillis - btnChangeTimestampMs) > startResetBtnPressThresholdMs)
    {
      doStart = false;
      doReset = true;
    }
  }
  else if ((lastButtonState != HIGH) && (buttonState == HIGH))
  {
    // Button was released
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
  scoreboard.Start();
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
