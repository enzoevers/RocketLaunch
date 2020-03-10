#include "SpriteViewer.h"

//===============
// Constructor
//===============

SpriteViewer::SpriteViewer(CRGB* spriteData, bool* spriteMask, MatrixUtil::XY spriteSize, MatrixUtil::XY topLeftPosition, CRGB* matrixScreen, MatrixUtil::XY matrixSize)
  : m_spriteData(spriteData),
    m_spriteMask(spriteMask),
    m_matrixScreen(matrixScreen),
    m_spriteSize(spriteSize),
    m_matrixSize(matrixSize),
    m_topLeftPosition(topLeftPosition)
{

}

//===============
// Public functions
//===============

bool SpriteViewer::SetScreen(CRGB* matrixScreen, MatrixUtil::XY matrixSize)
{
  if (matrixScreen == nullptr)
  {
    return false;
  }

  if (matrixSize.X <= 0 || matrixSize.Y <= 0)
  {
    return false;
  }

  m_matrixSize = matrixSize;
  m_matrixScreen = matrixScreen;
  return true;
}

bool SpriteViewer::SetSprite(CRGB* spriteData, bool* spriteMask, MatrixUtil::XY spriteSize, MatrixUtil::XY topLeftPosition)
{
  if (spriteData == nullptr || spriteMask == nullptr)
  {
    return false;
  }

  if (spriteSize.X <= 0 || spriteSize.Y <= 0)
  {
    return false;
  }

  m_spriteData = spriteData;
  m_spriteMask = spriteMask;
  m_spriteSize = spriteSize;
  m_topLeftPosition = topLeftPosition;
  return true;
}

void SpriteViewer::SetPosition(MatrixUtil::XY topLeftPosition)
{
  m_topLeftPosition = topLeftPosition;
}

void SpriteViewer::TranslateSprite(MatrixUtil::XY translation)
{
  m_topLeftPosition.X += m_topLeftPosition.X;
  m_topLeftPosition.Y += m_topLeftPosition.Y;
}

bool SpriteViewer::SetSpriteOnScreen()
{
  if (m_spriteData == nullptr || m_spriteMask == nullptr)
  {
    return false;
  }

  if (m_matrixSize.X <= 0 || m_matrixSize.Y <= 0)
  {
    return false;
  }

  if (m_spriteSize.X <= 0 || m_spriteSize.Y <= 0)
  {
    return false;
  }

  // Check it the complete sprite is out of the matrix
  MatrixUtil::XY bottomRight = {m_topLeftPosition.X + (m_spriteSize.X - 1), m_topLeftPosition.Y + (m_spriteSize.Y - 1)};

  if (m_topLeftPosition.X >= m_matrixSize.X || m_topLeftPosition.Y >= m_matrixSize.Y
      || bottomRight.X < 0 || bottomRight.Y < 0)
  {
    // Nothing to be drawn.
    return false;
  }

  // Update the matrix screen data with the sprite data
  for (size_t c = 0; c < m_spriteSize.X; c++)
  {
    for (size_t r = 0; r < m_spriteSize.Y; r++)
    {
      MatrixUtil::XY matrixCoordinate = { m_topLeftPosition.X + c, m_topLeftPosition.Y + r };

      if (CoordinateIsInScreen(matrixCoordinate))
      {
        size_t matrixIndex = MatrixUtil::MatrixToLinearIndex(matrixCoordinate.X, matrixCoordinate.Y, m_matrixSize.X, m_matrixSize.Y);
        size_t spriteIndex = MatrixUtil::MatrixToLinearIndex(c, r, m_spriteSize.X, m_spriteSize.Y);

        if (m_spriteMask[spriteIndex])
        {
          m_matrixScreen[matrixIndex] = m_spriteData[spriteIndex];
        }
      }
    }
  }

  return true;
}


//===============
// Private functions
//===============

bool SpriteViewer::CoordinateIsInScreen(const MatrixUtil::XY& coordinate)
{
  bool isInScreen = true;

  if (coordinate.X >= m_matrixSize.X || coordinate.Y >= m_matrixSize.Y
      || coordinate.X < 0 || coordinate.Y < 0)
  {
    isInScreen = false;
  }

  return isInScreen;
}
