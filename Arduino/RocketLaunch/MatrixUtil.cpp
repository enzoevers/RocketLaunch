#include "MatrixUtil.h"

const size_t MatrixUtil::verticalSerpentineMatrixToLinearIndex(const size_t column, const size_t row, const size_t numColums, const size_t numRows)
{
  if (column >= numColums || row >= numRows)
  {
    return 0;
  }

  size_t linearIndex = column * numRows;

#if defined(ZERO_TOP_LEFT)
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

#elif defined(ZERO_BOTTOM_RIGHT)
  size_t maxLinearIndex = (numColums * numRows) - 1;

  if ((column % 2) == 0)
  {
    // Columns with an even index
    linearIndex += ((numRows - 1) - row);
  }
  else
  {
    // Columns with an uneven index
    linearIndex += row;
  }

  linearIndex = maxLinearIndex - linearIndex;

#endif

  return linearIndex;
}
