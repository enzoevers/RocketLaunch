#include "MatrixUtil.h"

const size_t MatrixUtil::VerticalSerpentineMatrixToLinearIndex(const size_t column, const size_t row, const size_t numColums, const size_t numRows)
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
