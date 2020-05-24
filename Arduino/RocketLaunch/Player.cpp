#include "Player.h"

//==========
// Public
//==========
void Player::reset()
{
  m_currentPoints = 0;
}

const uint32_t Player::addPoints(const uint8_t earnedPoints)
{
  m_currentPoints += earnedPoints;
  return m_currentPoints;
}

const uint32_t Player::getCurrentPoints()
{
  return m_currentPoints;
}
