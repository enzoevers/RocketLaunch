#pragma once

#include <stdint.h>

class Player
{
  public:
    void reset();
    
    // Arguments:
    //  earnedPoints: the points earned from hitting a target
    //
    // Return: the new total score
    const uint32_t addPoints(const uint8_t earnedPoints);
    
    const uint32_t getCurrentPoints();

  private:
    uint32_t m_currentPoints = 0;
};
