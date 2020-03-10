#pragma once

#define SCOREBOARD_DATA_PIN 10

#include "MatrixUtil.h"
#include "SpriteViewer.h"
#include <FastLED.h>

//         ||                                                  ||
//         ||                                                  ||
//         DIN                                                DOUT
//     c c c c c c c c c c c c c c c c c c c c c c c c c c c c c c c c
//     0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3
//     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
//     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// r0 |0 →↓                                                          |
// r1 |↓ ↑ ↓                                                          |
// r2 |↓ ↑ ↓                                                          |
// r3 |↓ ↑ ↓                                                          |
// r4 |↓ ↑ ↓                                                          |
// r5 |↓ ↑ ↓                                                          |
// r6 |↓ ↑ ↓                                                          |
// r8 |7 ↑ →                                                         |
//     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//
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
    Scoreboard();
    ~Scoreboard();
    
    void Update();

    bool SetPlayerCount(const uint8_t numPlayers);
    uint8_t GetPlayerCount();

    void Start();
    void Reset();
    bool UpdateScore(uint32_t newScore, uint8_t player);
    bool ReachedMaxScore(uint8_t player);

    uint32_t GetWriteTime();

  private:
    void AnimationIdleNoGame();
    void AnimationStart();
    void AnimationIdleInGame();
    void AnimationNewScore(uint32_t newScore, uint8_t player);
    void AnimationVictory(uint8_t player);
    void ClearMatrix();

    // Arguments:
    //  sprite: data of the 2D sprite in a linear array to show on the matrix.
    //  spriteMask: this mask is a linear array (similar to 'sprite') used to determine which pixels in the 'sprite' array to show on the matrix
    //  spriteSize: the width (.X) and height (.Y) of the sprite
    //  topLeftOrigin: origin of the sprite
    //
    // If the sprite does not completely fit on the matrix, only the visible pixels are shown
    //void ShowSprite2d(const CRGB* sprite, const bool* spriteMask, const XY& spriteSize, const XY& topLeftOrigin);

    const uint16_t m_maxUpdateTimeMs = 1000 / 100; // 1 second / 100 FPS = 10ms
    uint16_t m_updateTimeMs = 0;

    const uint8_t GetFPS() {
      return 1000 / m_updateTimeMs;  // 1 second / m_updateTimeMs
    }

    const uint16_t m_durationMsIdleNoGame = 2500;
    const uint16_t m_durationMsStart = 2000;
    const uint16_t m_durationMsIdleInGame = 2000;
    const uint16_t m_durationMsNewScore = 2000;
    const uint16_t m_durationMsVictory = 2000;


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

    bool m_doIdleAnimation = false;

    //-----
    // ball sprite
    const MatrixUtil::XY m_ballSpriteSize = {4, 4};
    MatrixUtil::XY m_ballSpriteTopLeft = { -m_ballSpriteSize.X, 2};
    CRGB m_ballSpriteData[4*4] =
    {
      CHSV(0, 255, 0), CHSV(0, 255, 0), CHSV(0, 255, 0), CHSV(0, 255, 0),
      CHSV(0, 255, 0), CHSV(0, 255, 0), CHSV(0, 255, 0), CHSV(0, 255, 0),
      CHSV(0, 255, 0), CHSV(0, 255, 0), CHSV(0, 255, 0), CHSV(0, 255, 0),
      CHSV(0, 255, 0), CHSV(0, 255, 0), CHSV(0, 255, 0), CHSV(0, 255, 0)
    };
    bool m_ballSpriteMask[4*4] =
    {
      0, 1, 1, 0,
      1, 1, 1, 1,
      1, 1, 1, 1,
      0, 1, 1, 0
    };

    SpriteViewer* m_ballSprite = new SpriteViewer(m_ballSpriteData, m_ballSpriteMask, m_ballSpriteSize, m_ballSpriteTopLeft, m_ledMatrix, m_matrixScreenSize);
    //---
};
