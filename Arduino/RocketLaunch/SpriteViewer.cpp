#include "SpriteViewer.h"

//===============
// Constructor
//===============

SpriteViewer::SpriteViewer(Sprite sprite, CRGB* matrixScreen, MatrixUtil::XY matrixSize)
  : m_sprite(sprite),
    m_matrixScreen(matrixScreen),
    m_matrixSize(matrixSize)
{
}

//===============
// Public functions
//===============

const MatrixUtil::XY SpriteViewer::getSpriteSize()
{
  return m_sprite.spriteSize;
}

bool SpriteViewer::setScreen(CRGB* matrixScreen, MatrixUtil::XY matrixSize)
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

bool SpriteViewer::setSprite(Sprite sprite, MatrixUtil::XY spriteTopLeftPosition)
{
  if (sprite.spriteMask == nullptr)
  {
    return false;
  }

  if (sprite.spriteSize.X <= 0 || sprite.spriteSize.Y <= 0)
  {
    return false;
  }

  m_sprite = sprite;
  m_topLeftPosition = spriteTopLeftPosition;
  return true;
}

void SpriteViewer::setPriteSolidColor(CHSV newSolidColor)
{
  m_sprite.colorHSV = newSolidColor;
}

void SpriteViewer::setPosition(MatrixUtil::XY topLeftPosition)
{
  m_topLeftPosition = topLeftPosition;
}

void SpriteViewer::translateSprite(MatrixUtil::XY translation)
{
  m_topLeftPosition.X += translation.X;
  m_topLeftPosition.Y += translation.Y;
}

bool SpriteViewer::setSpriteOnScreen()
{
  if (m_sprite.spriteMask == nullptr)
  {
    return false;
  }

  if (m_sprite.spriteSize.X <= 0 || m_sprite.spriteSize.Y <= 0)
  {
    return false;
  }

  if (m_matrixSize.X <= 0 || m_matrixSize.Y <= 0)
  {
    return false;
  }

  // Check it the complete sprite is out of the matrix
  MatrixUtil::XY bottomRight = {m_topLeftPosition.X + (m_sprite.spriteSize.X - 1), m_topLeftPosition.Y + (m_sprite.spriteSize.Y - 1)};

  if (m_topLeftPosition.X >= m_matrixSize.X || m_topLeftPosition.Y >= m_matrixSize.Y
      || bottomRight.X < 0 || bottomRight.Y < 0)
  {
    // Nothing to be drawn.
    return false;
  }

  // Update the matrix screen data with the sprite data
  for (size_t c = 0; c < m_sprite.spriteSize.X; c++)
  {
    for (size_t r = 0; r < m_sprite.spriteSize.Y; r++)
    {
      MatrixUtil::XY matrixCoordinate = { m_topLeftPosition.X + c, m_topLeftPosition.Y + r };

      if (coordinateIsInScreen(matrixCoordinate))
      {
        size_t matrixIndex = MatrixUtil::verticalSerpentineMatrixToLinearIndex(matrixCoordinate.X, matrixCoordinate.Y, m_matrixSize.X, m_matrixSize.Y);
        size_t spriteIndex = MatrixUtil::verticalSerpentineMatrixToLinearIndex(c, r, m_sprite.spriteSize.X, m_sprite.spriteSize.Y);

        const uint64_t spriteRowMask = 1 << ((m_sprite.spriteSize.X - 1) - c);
        if (m_sprite.spriteMask[r] & spriteRowMask)
        {
          m_matrixScreen[matrixIndex] = m_sprite.colorHSV;
        }
      }
    }
  }

  return true;
}


//===============
// Private functions
//===============

bool SpriteViewer::coordinateIsInScreen(const MatrixUtil::XY& coordinate)
{
  bool isInScreen = true;

  if (coordinate.X >= m_matrixSize.X || coordinate.Y >= m_matrixSize.Y
      || coordinate.X < 0 || coordinate.Y < 0)
  {
    isInScreen = false;
  }

  return isInScreen;
}
