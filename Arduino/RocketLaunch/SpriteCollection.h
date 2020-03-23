#pragma once

#include "SpriteViewer.h"

// For future expandability a SD card module (https://www.tinytronics.nl/shop/nl/diversen/opslag/microsd-kaart-adapter-module-3.3v-5v-met-level-shifter)
// could be used for storing more spritis


namespace SpriteCollection
{

const extern Sprite ballSprite;

const extern Sprite character_0_Sprite;
const extern Sprite character_1_Sprite;
const extern Sprite character_2_Sprite;
const extern Sprite character_3_Sprite;
const extern Sprite character_4_Sprite;
const extern Sprite character_5_Sprite;
const extern Sprite character_6_Sprite;
const extern Sprite character_7_Sprite;
const extern Sprite character_8_Sprite;

// When using 'character_9_Sprite' (which is a reference to 'character_6_Sprite') 
// the user should flip the the sprite once in the y-axis and once in the x-axis.
// This is to reduce memory usage
const extern Sprite& character_9_Sprite;

};
