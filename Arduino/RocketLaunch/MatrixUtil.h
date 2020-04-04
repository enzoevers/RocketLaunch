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

//         ||                                                  ||
//         ||                                                  ||
//         DIN                                                DOUT
//     c c c c c c c c c c c c c c c c c c c c c c c c c c c c c c c c
//     0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3
//     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
//     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// r0 |0 →↓                                                          |
// r1 |↓ ↑ ↓                                                          |
// r2 |↓ ↑ ↓                                                          |
// r3 |↓ ↑ ↓                                                          |
// r4 |↓ ↑ ↓                                                          |
// r5 |↓ ↑ ↓                                                          |
// r6 |↓ ↑ ↓                                                          |
// r8 |7 ↑ →                                                         |
//     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//
// Layout for a vertical serpentine connected matrix
const size_t VerticalSerpentineMatrixToLinearIndex(const size_t column, const size_t row, const size_t numColums, const size_t numRows);
}
