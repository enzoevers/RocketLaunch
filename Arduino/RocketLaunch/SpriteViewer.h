#pragma once

#include "MatrixUtil.h"
#include <FastLED.h>

class SpriteViewer
{
  public:
    SpriteViewer(CRGB* spriteData, bool* spriteMask, MatrixUtil::XY spriteSize, MatrixUtil::XY topLeftPosition, CRGB* matrixScreen, MatrixUtil::XY matrixSize);

    bool SetScreen(CRGB* matrixScreen, MatrixUtil::XY matrixSize);
    bool SetSprite(CRGB* spriteData, bool* spriteMask, MatrixUtil::XY spriteSize, MatrixUtil::XY topLeftPosition);
    
    void SetPosition(MatrixUtil::XY topLeftPosition);
    void TranslateSprite(MatrixUtil::XY translation);

    // This does not show the sprite.
    // It only sets the sprite data in the screen.
    bool SetSpriteOnScreen();

  private:
    bool CoordinateIsInScreen(const MatrixUtil::XY& coordinate);
  
    MatrixUtil::XY m_spriteSize = {0, 0};
    MatrixUtil::XY m_matrixSize = {0, 0};
    MatrixUtil::XY m_topLeftPosition = {0, 0};

    CRGB* m_matrixScreen = nullptr;
    CRGB* m_spriteData = nullptr;
    bool* m_spriteMask = nullptr;
};
