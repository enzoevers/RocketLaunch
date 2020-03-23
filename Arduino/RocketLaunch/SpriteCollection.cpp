#include "SpriteCollection.h"
#include "Colors.h"

namespace SpriteCollection
{

//-----
// ballSprite
const int16_t ballSpriteWidth = 4;
const int16_t ballSpriteHeight = 4;
const uint32_t ballSpriteLedCount = ballSpriteWidth * ballSpriteHeight;

const uint32_t ballSpriteMask[ballSpriteHeight] =
{
  0b0110,
  0b1111,
  0b1111,
  0b0110
};

const Sprite ballSprite
{
  {ballSpriteWidth, ballSpriteHeight},
  CHSV(HSV_RAINDBOW_RED, 255, 255),
  ballSpriteMask
};
//-----


//-----
// character_0_Sprite
const int16_t character_0_SpriteWidth = 3;
const int16_t character_0_SpriteHeight = 4;
const uint32_t character_0_SpriteLedCount = character_0_SpriteWidth * character_0_SpriteHeight;

const uint32_t character_0_SpriteMask[character_0_SpriteHeight] =
{
  0b010,
  0b101,
  0b101,
  0b010
};

const Sprite character_0_Sprite
{
  {character_0_SpriteWidth, character_0_SpriteHeight},
  CHSV(HSV_RAINDBOW_RED, 255, 255),
  character_0_SpriteMask
};
//-----

//-----
// character_1_Sprite
const int16_t character_1_SpriteWidth = 3;
const int16_t character_1_SpriteHeight = 5;
const uint32_t character_1_SpriteLedCount = character_1_SpriteWidth * character_1_SpriteHeight;

const uint32_t character_1_SpriteMask[character_1_SpriteHeight] =
{

  0b010,
  0b110,
  0b010,
  0b010,
  0b111
};

const Sprite character_1_Sprite
{
  {character_1_SpriteWidth, character_1_SpriteHeight},
  CHSV(HSV_RAINDBOW_RED, 255, 255),
  character_1_SpriteMask
};
//-----

//-----
// character_2_Sprite
const int16_t character_2_SpriteWidth = 3;
const int16_t character_2_SpriteHeight = 5;
const uint32_t character_2_SpriteLedCount = character_2_SpriteWidth * character_2_SpriteHeight;

const uint32_t character_2_SpriteMask[character_2_SpriteHeight] =
{

  0b010,
  0b101,
  0b001,
  0b010,
  0b111
};

const Sprite character_2_Sprite
{
  {character_2_SpriteWidth, character_2_SpriteHeight},
  CHSV(HSV_RAINDBOW_RED, 255, 255),
  character_2_SpriteMask
};
//-----

//-----
// character_3_Sprite
const int16_t character_3_SpriteWidth = 3;
const int16_t character_3_SpriteHeight = 5;
const uint32_t character_3_SpriteLedCount = character_3_SpriteWidth * character_3_SpriteHeight;

const uint32_t character_3_SpriteMask[character_3_SpriteHeight] =
{

  0b111,
  0b001,
  0b011,
  0b001,
  0b111
};

const Sprite character_3_Sprite
{
  {character_3_SpriteWidth, character_3_SpriteHeight},
  CHSV(HSV_RAINDBOW_RED, 255, 255),
  character_3_SpriteMask
};
//-----

//-----
// character_4_Sprite
const int16_t character_4_SpriteWidth = 3;
const int16_t character_4_SpriteHeight = 4;
const uint32_t character_4_SpriteLedCount = character_4_SpriteWidth * character_4_SpriteHeight;

const uint32_t character_4_SpriteMask[character_4_SpriteHeight] =
{

  0b001,
  0b011,
  0b101,
  0b001
};

const Sprite character_4_Sprite
{
  {character_4_SpriteWidth, character_4_SpriteHeight},
  CHSV(HSV_RAINDBOW_RED, 255, 255),
  character_4_SpriteMask
};
//-----

//-----
// character_5_Sprite
const int16_t character_5_SpriteWidth = 3;
const int16_t character_5_SpriteHeight = 5;
const uint32_t character_5_SpriteLedCount = character_5_SpriteWidth * character_5_SpriteHeight;

const uint32_t character_5_SpriteMask[character_5_SpriteHeight] =
{

  0b111,
  0b100,
  0b110,
  0b001,
  0b110
};

const Sprite character_5_Sprite
{
  {character_5_SpriteWidth, character_5_SpriteHeight},
  CHSV(HSV_RAINDBOW_RED, 255, 255),
  character_5_SpriteMask
};
//-----

};
