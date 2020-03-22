#include "SpriteCollection.h"
#include "Colors.h"

namespace SpriteCollection
{

//-----
// ballSprite
const int16_t ballSpriteWidth = 4;
const int16_t ballSpriteHeight = 4;
const MatrixUtil::XY ballSpriteSize = {ballSpriteWidth, ballSpriteHeight};
const uint32_t ballSpriteLedCount = ballSpriteSize.X * ballSpriteSize.Y;
CHSV ballSpriteData[ballSpriteLedCount] =
{
  CHSV(0, 0, 0), CHSV(0, 0, 0), CHSV(0, 0, 0), CHSV(0, 0, 0),
  CHSV(0, 0, 0), CHSV(0, 0, 0), CHSV(0, 0, 0), CHSV(0, 0, 0),
  CHSV(0, 0, 0), CHSV(0, 0, 0), CHSV(0, 0, 0), CHSV(0, 0, 0),
  CHSV(0, 0, 0), CHSV(0, 0, 0), CHSV(0, 0, 0), CHSV(0, 0, 0)
};
const uint64_t ballSpriteMask[ballSpriteHeight] =
{
  0b0110,
  0b1111,
  0b1111,
  0b0110
};

const Sprite ballSprite
{
  ballSpriteSize,
  ballSpriteData,
  ballSpriteMask
};
//-----


//-----
// character_R_Sprite
const int16_t character_R_SpriteWidth = 5;
const int16_t character_R_SpriteHeight = 8;
const MatrixUtil::XY character_R_SpriteSize = {character_R_SpriteWidth, character_R_SpriteHeight};
const uint32_t character_R_SpriteLedCount = character_R_SpriteSize.X * character_R_SpriteSize.Y;
CHSV character_R_SpriteData[character_R_SpriteLedCount] =
{
  CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255),
  CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255),
  CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255),
  CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255),
  CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255),
  CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255),
  CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255),
  CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255), CHSV(HSV_RAINDBOW_PURPLE, 255, 255)
};
const uint64_t character_R_SpriteMask[character_R_SpriteHeight] =
{
  0b00000,
  0b11100,
  0b10011,
  0b11100,
  0b11110,
  0b11011,
  0b11011,
  0b00000
};

const Sprite character_R_Sprite
{
  character_R_SpriteSize,
  character_R_SpriteData,
  character_R_SpriteMask
};
//-----

};
