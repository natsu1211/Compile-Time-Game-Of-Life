/* ------------------------------
# author  : natsu1211
# date    : 2018-09-08
------------------------------- */

#ifndef BOARD_H_0MFOR8WC
#define BOARD_H_0MFOR8WC
#include <array>
#include <cstdint>
#include "random.h"

#ifndef COL
#define COL 1
#endif /* ifndef COL */

#ifndef ROW
#define ROW 1
#endif /* ifndef ROW */

#ifndef RSEED
#define RSEED 1
#endif /* ifndef RSEED */

template<int Col, int Row>
using Board = std::array<std::array<bool, Row>, Col>;

using GameBoard = Board<COL, ROW>;

static constexpr GameBoard generateInitBoard()
{
    GameBoard board{};
    auto rand = Random(static_cast<unsigned>(RSEED));
    for (int i = 0; i < COL; ++i) {
        for (int j = 0; j < ROW; ++j) {
            board[i][j] = rand.range(0, 2);
        }
    }
    return board;
}

#endif /* end of include guard: BOARD_H_0MFOR8WC */
