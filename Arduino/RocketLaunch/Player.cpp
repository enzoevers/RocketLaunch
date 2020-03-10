#include "Player.h"

//==========
// Public
//==========
void Player::Reset()
{
  m_currentPoints = 0;
}

uint32_t Player::AddPoints(uint8_t earnedPoints)
{
  m_currentPoints += earnedPoints;
  return m_currentPoints;
}
