#include "Player.h"

//==========
// Public
//==========
void Player::Reset()
{
  m_currentPoints = 0;
}

const uint32_t Player::AddPoints(const uint8_t earnedPoints)
{
  m_currentPoints += earnedPoints;
  return m_currentPoints;
}

const uint32_t Player::GetCurrentPoints()
{
  return m_currentPoints;
}
