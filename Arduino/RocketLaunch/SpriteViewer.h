#pragma once

#include "MatrixUtil.h"
#include <FastLED.h>

struct Sprite
{
  MatrixUtil::XY spriteSize;
  CHSV colorHSV;

  // Bitmask per row
  // A sprite may only have a maximum of 8 columns to reduce memory usage
  uint8_t* spriteMask; 
};

class SpriteViewer
{
  public:
    SpriteViewer(Sprite sprite, CRGB* matrixScreen, MatrixUtil::XY matrixSize);

    const MatrixUtil::XY getSpriteSize();
    const MatrixUtil::XY getPosition() { return m_topLeftPosition; }
    const Sprite& getSprite() { return m_sprite; }

    bool setScreen(CRGB* matrixScreen, MatrixUtil::XY matrixSize);
    bool setSprite(Sprite sprite, MatrixUtil::XY spriteTopLeftPosition);

    void setPriteSolidColor(CHSV newSolidColor);
    void setPosition(MatrixUtil::XY topLeftPosition);
    void translateSprite(MatrixUtil::XY translation);

    // This does not show the sprite.
    // It only sets the sprite data in the screen.
    // FastLed.show() should be called separately
    bool setSpriteOnScreen();

  private:
    bool coordinateIsInScreen(const MatrixUtil::XY& coordinate);

    Sprite m_sprite;

    MatrixUtil::XY m_matrixSize = {0, 0};
    MatrixUtil::XY m_topLeftPosition = {0, 0};

    CRGB* m_matrixScreen = nullptr;
};
