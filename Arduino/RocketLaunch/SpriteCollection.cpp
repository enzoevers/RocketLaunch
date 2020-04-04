#include "SpriteCollection.h"
#include "Colors.h"

namespace SpriteCollection
{

//-----
// ballSprite
const uint8_t ballSpriteWidth = 4;
const uint8_t ballSpriteHeight = 4;
const uint16_t ballSpriteLedCount = ballSpriteWidth * ballSpriteHeight;

const uint8_t ballSpriteMask[ballSpriteHeight] =
{
  0b0110,
  0b1111,
  0b1111,
  0b0110
};

const Sprite ballSprite
{
  {ballSpriteWidth, ballSpriteHeight},
  CHSV(0, 0, 0),
  ballSpriteMask
};
//-----


//====================
// Numeric sprites
//====================

//-----
// character_0_Sprite
const uint8_t character_0_SpriteWidth = 3;
const uint8_t character_0_SpriteHeight = 4;

const uint8_t character_0_SpriteMask[character_0_SpriteHeight] =
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
const uint8_t character_1_SpriteWidth = 3;
const uint8_t character_1_SpriteHeight = 5;

const uint8_t character_1_SpriteMask[character_1_SpriteHeight] =
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
const int8_t character_2_SpriteWidth = 3;
const int8_t character_2_SpriteHeight = 5;

const uint8_t character_2_SpriteMask[character_2_SpriteHeight] =
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
const uint8_t character_3_SpriteWidth = 3;
const uint8_t character_3_SpriteHeight = 5;

const uint8_t character_3_SpriteMask[character_3_SpriteHeight] =
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
const uint8_t character_4_SpriteWidth = 3;
const uint8_t character_4_SpriteHeight = 4;

const uint8_t character_4_SpriteMask[character_4_SpriteHeight] =
{
  0b011,
  0b101,
  0b111,
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
const uint8_t character_5_SpriteWidth = 3;
const uint8_t character_5_SpriteHeight = 5;

const uint8_t character_5_SpriteMask[character_5_SpriteHeight] =
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

//-----
// character_6_Sprite
const uint8_t character_6_SpriteWidth = 3;
const uint8_t character_6_SpriteHeight = 5;

const uint8_t character_6_SpriteMask[character_6_SpriteHeight] =
{

  0b011,
  0b100,
  0b110,
  0b101,
  0b010
};

const Sprite character_6_Sprite
{
  {character_6_SpriteWidth, character_6_SpriteHeight},
  CHSV(HSV_RAINDBOW_RED, 255, 255),
  character_6_SpriteMask
};
//-----

//-----
// character_7_Sprite
const int16_t character_7_SpriteWidth = 3;
const int16_t character_7_SpriteHeight = 4;

const uint8_t character_7_SpriteMask[character_7_SpriteHeight] =
{
  0b111,
  0b001,
  0b010,
  0b100
};

const Sprite character_7_Sprite
{
  {character_7_SpriteWidth, character_7_SpriteHeight},
  CHSV(HSV_RAINDBOW_RED, 255, 255),
  character_7_SpriteMask
};
//-----

//-----
// character_8_Sprite
const uint8_t character_8_SpriteWidth = 3;
const uint8_t character_8_SpriteHeight = 5;

const uint8_t character_8_SpriteMask[character_8_SpriteHeight] =
{

  0b010,
  0b101,
  0b010,
  0b101,
  0b010
};

const Sprite character_8_Sprite
{
  {character_8_SpriteWidth, character_8_SpriteHeight},
  CHSV(HSV_RAINDBOW_RED, 255, 255),
  character_8_SpriteMask
};
//-----

//-----
// character_9_Sprite
const uint8_t character_9_SpriteWidth = 3;
const uint8_t character_9_SpriteHeight = 5;

const uint8_t character_9_SpriteMask[character_9_SpriteHeight] =
{
  0b010,
  0b101,
  0b011,
  0b001,
  0b110
};

const Sprite character_9_Sprite
{
  {character_9_SpriteWidth, character_9_SpriteHeight},
  CHSV(HSV_RAINDBOW_RED, 255, 255),
  character_9_SpriteMask
};
//-----

};
