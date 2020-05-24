#pragma once

//====================
//
// Dependecies:
//  - FastLED | V3.3.3 | https://github.com/FastLED/FastLED | Get it using the Arduino IDE "Sketch > Include Library > Manage Libraries > Search for FastLED (V 3.3.3)"
//
//====================

#define SCOREBOARD_DATA_PIN 8

// CREATE_NUMBER_SPRITE(2) outputs: new SpriteViewer(&SpriteCollection::character_2_Sprite, m_ledMatrix, m_matrixScreenSize)
#define CREATE_NUMBER_SPRITE(n) (new SpriteViewer(SpriteCollection::character_##n##_Sprite, m_ledMatrix, m_matrixScreenSize))

#include "MatrixUtil.h"
#include "SpriteViewer.h"
#include "SpriteCollection.h"
#include "GameStateManager.h"
#include "Player.h"
#include "Colors.h"
#include <FastLED.h>

// WS2812B datasheet: https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf
// -> WS2812B-V2 (on the matrix) datasheet: https://d2j2m4p6r3pg95.cloudfront.net/module_files/led-cube/assets/datasheets/WS2812B.pdf
//
// Calculating the FPS
// -------------------
// A WS2812B LED expects data a rate of 800Kbps (800.000 bits per second).
// The data for one LED consists of 24 bits (8 green,8 red, 8 blue).
// This means data for one led takes:
//    (1.000.000.000 (ns) / 800.000 (bits)) * 24 (bits per RGB LED) =
//    1.250 (ns) * 24 (bits per RGB LED) =
//    30.000 ns per LED (30 us/RGB LED)
//
// To send a new dataframe the data signal should be pulled low for a certain amount of time.
// The datasheet for both V1 and V2 state >50us. But Adafruit has an article (https://blog.adafruit.com/2017/05/03/psa-the-ws2812b-rgb-led-has-been-revised-will-require-code-tweak/)
// stating the new version need >300us. Looking at the logic analyser output it seems that FastLED uses a reset time between 1 ms and 2 ms. Lets use the worst case 2 ms (2.000 us).
// The matrix has 256 RGB LEDs. This means that the average frame rate is:
//    1.000.000 (us) / ((30 (us) * 256 (RGB LEDs)) + 2.000 (us)) ~=
//    103 FPS

class Scoreboard
{
  public:
    Scoreboard(void (*scoreboardAnimationCompleteCallback)(void));
    ~Scoreboard();

    void update(GameState state);

    bool setPlayerCount(const uint8_t numPlayers);
    uint8_t getPlayerCount();
    
    void reset();
    uint32_t updateScore(uint32_t points, uint8_t player);
    bool reachedMaxScore(uint8_t player);

    uint32_t getWriteTime();

  private:
    void (*m_scoreboardAnimationCompleteCallback)(void);
    
    // These functions return:
    //  true: all steps of one anumation round are done
    //  false: not all steps of one animation round are executed yet
    bool animationIdleNoGame();
    bool animationStart();
    bool animationIdleInGame();
    void animationIdleInGame_singlePlayer();
    void animationIdleInGame_dualPlayer();
    void animationIdleInGame_writePoints(char* scoreStringBuf, uint8_t numChars, CHSV color, MatrixUtil::XY startIndexSprite);
    bool animationNewScore(uint32_t newScore, uint8_t player);
    bool animationVictory(uint8_t player);
    bool animationStopGame();
    bool clearMatrix();

    const uint16_t m_durationMsIdleNoGame = 2500;
    const uint16_t m_durationMsStart = 6000;
    const uint16_t m_durationMsIdleInGame = 2000;
    const uint16_t m_durationMsNewScore = 1000;
    const uint16_t m_durationMsVictory = 4000;
    const uint16_t m_durationMsStopGame = 1500;

    uint16_t m_numStepsIdleNoGame = 256/2;
    uint16_t m_numStepsStart = 5;
    uint16_t m_numStepsIdleInGame = 48;
    uint16_t m_numStepsNewScore = 1;
    uint16_t m_numStepsVictory = 1;
    uint16_t m_numStepsStopGame = 32/2 + 7; // The animation is symmetrical in the vertical center of the matric (32/2)
                                            // When the animation reached the middle 7 extra leds need to go down
    
    uint16_t m_curStepIdleNoGame = 0;
    uint16_t m_curStepStart = 0;
    uint16_t m_curStepIdleInGame = 0;
    uint16_t m_curStepNewScore = 0;
    uint16_t m_curStepVictory = 0;
    uint16_t m_curStepStopGame = 0;

    const uint16_t m_minUpdateTimeMs = 1000 / 100; // 1 second / 100 FPS = 10ms
    uint16_t m_updateTimeMs = 40; // Refresh rate of 25Hz
    unsigned long m_lastMillisScreenUpdate = 0;
    bool m_updateScreenNow = false;

    const uint8_t GetFPS() {
      return 1000 / m_updateTimeMs;  // 1 second / m_updateTimeMs
    }

    GameState m_prevState = GameState::StopGame;

    const MatrixUtil::XY m_matrixScreenSize = { 32, 8 };
    static const int16_t m_numLeds = 32 * 8;
    CRGB m_ledMatrix[m_numLeds];

    uint16_t m_currentRow = 0;
    uint16_t m_currentColumn = 0;

    // HSV color values
    // When a value > 256 is assigned the values
    // will overflow to 0 again.
    uint8_t m_currentHue = 0;
    uint8_t m_currentSaturation = 255;
    uint8_t m_currentValue = 150;

    const uint8_t m_maxPlayers = 2;
    uint8_t m_playerCount = 1;
    uint8_t m_winningPlayer = 1;

    uint32_t m_lastScorePlayer1 = 0;
    uint32_t m_lastScorePlayer2 = 0;

    Player player1;
    Player player2; // player2 my not be used
    const Player* players[2] = { &player1, &player2 };

    const uint8_t m_huePlayer1 = HSV_RAINDBOW_GREEN;
    const uint8_t m_huePlayer2 = HSV_RAINDBOW_BLUE;

    // Sprites
    SpriteViewer* m_ballSpriteViewer = new SpriteViewer(SpriteCollection::ballSprite, m_ledMatrix, m_matrixScreenSize);

    SpriteViewer* m_numberSprites[10] =
    {
      CREATE_NUMBER_SPRITE(0),
      CREATE_NUMBER_SPRITE(1),
      CREATE_NUMBER_SPRITE(2),
      CREATE_NUMBER_SPRITE(3),
      CREATE_NUMBER_SPRITE(4),
      CREATE_NUMBER_SPRITE(5),
      CREATE_NUMBER_SPRITE(6),
      CREATE_NUMBER_SPRITE(7),
      CREATE_NUMBER_SPRITE(8),
      CREATE_NUMBER_SPRITE(9)
    };
};
