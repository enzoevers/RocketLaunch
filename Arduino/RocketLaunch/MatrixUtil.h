#pragma once

#include <stdint.h>
#include <stddef.h>

namespace MatrixUtil
{

struct XY
{
  int16_t X;
  int16_t Y;
};

static size_t MatrixToLinearIndex(size_t column, size_t row, size_t numColums, size_t numRows)
{
  if (column >= numColums || row >= numRows)
  {
    return 0;
  }

  size_t linearIndex = column * numRows;

  if ((column % 2) == 0)
  {
    // Columns with an even index
    linearIndex += row;
  }
  else
  {
    // Columns with an uneven index
    linearIndex += ((numRows - 1) - row);
  }

  return linearIndex;
}

}
