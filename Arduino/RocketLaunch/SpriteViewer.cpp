#include "SpriteViewer.h"

//===============
// Constructor
//===============

SpriteViewer::SpriteViewer(Sprite* sprite, MatrixUtil::XY spriteTopLeftPosition, CRGB* matrixScreen, MatrixUtil::XY matrixSize)
  : m_sprite(sprite),
    m_matrixScreen(matrixScreen),
    m_matrixSize(matrixSize),
    m_topLeftPosition(spriteTopLeftPosition)
{

}

//===============
// Public functions
//===============

const MatrixUtil::XY SpriteViewer::GetSpriteSize()
{
  if (m_sprite == nullptr)
  {
    return {0, 0};
  }
  else
  {
    return m_sprite->spriteSize;
  }
}

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

bool SpriteViewer::SetSprite(Sprite* sprite, MatrixUtil::XY spriteTopLeftPosition)
{
  if (sprite == nullptr)
  {
    return false;
  }

  if (sprite->spriteData == nullptr || sprite->spriteMask == nullptr)
  {
    return false;
  }

  if (sprite->spriteSize.X <= 0 || sprite->spriteSize.Y <= 0)
  {
    return false;
  }

  m_sprite->spriteData = sprite->spriteData;
  m_sprite->spriteMask = sprite->spriteMask;
  m_sprite->spriteSize = sprite->spriteSize;
  m_topLeftPosition = spriteTopLeftPosition;
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
  if (m_sprite == nullptr)
  {
    return false;
  }

  if (m_sprite->spriteData == nullptr || m_sprite->spriteMask == nullptr)
  {
    return false;
  }

  if (m_sprite->spriteSize.X <= 0 || m_sprite->spriteSize.Y <= 0)
  {
    return false;
  }

  if (m_matrixSize.X <= 0 || m_matrixSize.Y <= 0)
  {
    return false;
  }

  // Check it the complete sprite is out of the matrix
  MatrixUtil::XY bottomRight = {m_topLeftPosition.X + (m_sprite->spriteSize.X - 1), m_topLeftPosition.Y + (m_sprite->spriteSize.Y - 1)};

  if (m_topLeftPosition.X >= m_matrixSize.X || m_topLeftPosition.Y >= m_matrixSize.Y
      || bottomRight.X < 0 || bottomRight.Y < 0)
  {
    // Nothing to be drawn.
    return false;
  }

  // Update the matrix screen data with the sprite data
  for (size_t c = 0; c < m_sprite->spriteSize.X; c++)
  {
    for (size_t r = 0; r < m_sprite->spriteSize.Y; r++)
    {
      MatrixUtil::XY matrixCoordinate = { m_topLeftPosition.X + c, m_topLeftPosition.Y + r };

      if (CoordinateIsInScreen(matrixCoordinate))
      {
        size_t matrixIndex = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(matrixCoordinate.X, matrixCoordinate.Y, m_matrixSize.X, m_matrixSize.Y);
        size_t spriteIndex = MatrixUtil::VerticalSerpentineMatrixToLinearIndex(c, r, m_sprite->spriteSize.X, m_sprite->spriteSize.Y);

        const uint64_t spriteRowMask = 1 << ((m_sprite->spriteSize.X - 1) - c);
        if (m_sprite->spriteMask[r] & spriteRowMask)
        {
          m_matrixScreen[matrixIndex] = m_sprite->spriteData[spriteIndex];
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
