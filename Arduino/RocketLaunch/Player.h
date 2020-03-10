#pragma once

#include <stdint.h>

class Player
{
  public:
    void Reset();
    
    // Arguments:
    //  earnedPoints: the points earned from hitting a target
    //
    // Return: the new total score
    uint32_t AddPoints(uint8_t earnedPoints);

  private:
    uint32_t m_currentPoints = 0;
};
