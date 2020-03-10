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
const uint8_t playerSelectPin = 3;
const uint8_t gameModePin = 4;
const uint8_t startResetPin = 7;
//----------

//----------
// Serial
const uint8_t rxPin = 11;
const uint8_t txPin = 12;
const char startChar = '#';
const char stopChar = '%';
SerialCom mySerial(rxPin, txPin, 115200, startChar, stopChar);
//----------

//----------
// Micro:Bit communication
const uint8_t communicationEnablePin = 12;
MicroBitCommunication microBitCom(mySerial, communicationEnablePin);
uint8_t playerCount = 1;
uint8_t gameMode = 1;
//----------

//----------
// Scoreboard
// Set the pin in Scoreboard.h with the SCOREBOARD_DATA_PIN define
Scoreboard scoreboard;
//----------

//----------
// Players
Player player1;
Player player2; // player2 my not be used
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
//----------

//----------
// Confetti cannons
const uint8_t cannonPin = 2;
//----------

const uint32_t maxScore = 100;

void StartResetButtonPressed();
void InitializeGame();
void StartGame();
void StopGame();
void TargetHitCallback(const uint8_t player, const uint8_t points);

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

  if (doStart)
  {
    InitializeGame();
    StartGame();
    doStart = false;
  }
  else if (doReset)
  {
    StopGame();
    doReset = false;
  }
}

void StartResetButtonPoll()
{
  bool buttonState = digitalRead(startResetPin);

  if ((lastButtonState != LOW) && (buttonState == LOW))
  {
    // Button was pressed
    btnChangeTimestampMs = millis();
    lastButtonState = buttonState;
  }
  else if ((lastButtonState != HIGH) && (buttonState == HIGH))
  {  
    // Button was released
    if ((millis() - btnChangeTimestampMs) > startResetBtnPressThresholdMs)
    {
      doStart = false;
      doReset = true;
    }
    else
    {
      doStart = true;
      doReset = false;
    }

    lastButtonState = buttonState;
  }
}

void InitializeGame()
{
  // 0: 1 player ; 1: 2 players
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

void TargetHitCallback(const uint8_t player, const uint8_t points)
{
  uint32_t newScore = 0;

  switch (player)
  {
    case 1:
      {
        newScore = player1.AddPoints(points);
        break;
      }
    case 2:
      {
        newScore = player2.AddPoints(points);
        break;
      }
    default:
      {
        break;
      }
  };

  if (newScore >= maxScore)
  {
    scoreboard.ReachedMaxScore(player);
    digitalWrite(cannonPin, HIGH);
    delay(100);
    digitalWrite(cannonPin, LOW);
  }
  else
  {
    scoreboard.UpdateScore(newScore, player);
  }
}
