#pragma once

#include "MatrixUtil.h"
#include <FastLED.h>

struct Sprite
{
  MatrixUtil::XY spriteSize;
  CHSV* spriteData;
  uint64_t* spriteMask; // Bitmask per row
};

class SpriteViewer
{
  public:
    SpriteViewer(Sprite* sprite, MatrixUtil::XY spriteTopLeftPosition, CRGB* matrixScreen, MatrixUtil::XY matrixSize);

    const MatrixUtil::XY GetSpriteSize();

    bool SetScreen(CRGB* matrixScreen, MatrixUtil::XY matrixSize);
    bool SetSprite(Sprite* sprite, MatrixUtil::XY spriteTopLeftPosition);

    void SetPosition(MatrixUtil::XY topLeftPosition);
    void TranslateSprite(MatrixUtil::XY translation);

    // This does not show the sprite.
    // It only sets the sprite data in the screen.
    // FastLed.show() should be called separately
    bool SetSpriteOnScreen();

  private:
    bool CoordinateIsInScreen(const MatrixUtil::XY& coordinate);

    Sprite* m_sprite = nullptr;

    MatrixUtil::XY m_matrixSize = {0, 0};
    MatrixUtil::XY m_topLeftPosition = {0, 0};

    CRGB* m_matrixScreen = nullptr;
};
