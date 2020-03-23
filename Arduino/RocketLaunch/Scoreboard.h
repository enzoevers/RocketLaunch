#pragma once

#define SCOREBOARD_DATA_PIN 8

#include "MatrixUtil.h"
#include "SpriteViewer.h"
#include "SpriteCollection.h"
#include "GameState.h"
#include "Player.h"
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
    Scoreboard();
    ~Scoreboard();

    bool Update(GameState& state);

    bool SetPlayerCount(const uint8_t numPlayers);
    uint8_t GetPlayerCount();

    void Start();
    void Reset();
    bool UpdateScore(uint32_t newScore, uint8_t player);
    bool ReachedMaxScore(uint8_t player);

    uint32_t GetWriteTime();

  private:

    // These functions return:
    //  true: all steps of one anumation round are done
    //  false: not all steps of one animation round are executed yet
    bool AnimationIdleNoGame();
    bool AnimationStart();
    bool AnimationIdleInGame();
    bool AnimationNewScore(uint32_t newScore, uint8_t player);
    bool AnimationVictory(uint8_t player);
    bool AnimationStopGame();
    bool ClearMatrix();

    const uint16_t m_durationMsIdleNoGame = 2500;
    const uint16_t m_durationMsStart = 2000;
    const uint16_t m_durationMsIdleInGame = 2000;
    const uint16_t m_durationMsNewScore = 2000;
    const uint16_t m_durationMsVictory = 2000;
    const uint16_t m_durationMsStopGame = 2000;

    const uint16_t m_minUpdateTimeMs = 1000 / 100; // 1 second / 100 FPS = 10ms
    uint16_t m_updateTimeMs = 0;

    const uint8_t GetFPS() {
      return 1000 / m_updateTimeMs;  // 1 second / m_updateTimeMs
    }

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

    uint32_t m_currentScorePlayer1 = 0;
    uint32_t m_currentScorePlayer2 = 0;

    // Sprites
    SpriteViewer* m_ballSpriteViewer = new SpriteViewer(&SpriteCollection::ballSprite, m_ledMatrix, m_matrixScreenSize);
    SpriteViewer* m_character_0_SpriteViewer = new SpriteViewer(&SpriteCollection::character_0_Sprite, m_ledMatrix, m_matrixScreenSize);
    SpriteViewer* m_character_1_SpriteViewer = new SpriteViewer(&SpriteCollection::character_1_Sprite, m_ledMatrix, m_matrixScreenSize);
    SpriteViewer* m_character_2_SpriteViewer = new SpriteViewer(&SpriteCollection::character_2_Sprite, m_ledMatrix, m_matrixScreenSize);
    SpriteViewer* m_character_3_SpriteViewer = new SpriteViewer(&SpriteCollection::character_3_Sprite, m_ledMatrix, m_matrixScreenSize);
    SpriteViewer* m_character_4_SpriteViewer = new SpriteViewer(&SpriteCollection::character_4_Sprite, m_ledMatrix, m_matrixScreenSize);
    SpriteViewer* m_character_5_SpriteViewer = new SpriteViewer(&SpriteCollection::character_5_Sprite, m_ledMatrix, m_matrixScreenSize);
    SpriteViewer* m_character_6_SpriteViewer = new SpriteViewer(&SpriteCollection::character_6_Sprite, m_ledMatrix, m_matrixScreenSize);
    SpriteViewer* m_character_7_SpriteViewer = new SpriteViewer(&SpriteCollection::character_7_Sprite, m_ledMatrix, m_matrixScreenSize);
    SpriteViewer* m_character_8_SpriteViewer = new SpriteViewer(&SpriteCollection::character_8_Sprite, m_ledMatrix, m_matrixScreenSize);
    SpriteViewer* m_character_9_SpriteViewer = new SpriteViewer(&SpriteCollection::character_9_Sprite, m_ledMatrix, m_matrixScreenSize);

    SpriteViewer* m_numberSprites[10] =
    {
      m_character_0_SpriteViewer,
      m_character_1_SpriteViewer,
      m_character_2_SpriteViewer,
      m_character_3_SpriteViewer,
      m_character_4_SpriteViewer,
      m_character_5_SpriteViewer,
      m_character_6_SpriteViewer,
      m_character_7_SpriteViewer,
      m_character_8_SpriteViewer,
      m_character_9_SpriteViewer
    };
};
