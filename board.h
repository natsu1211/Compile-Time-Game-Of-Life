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
struct Board
{
    std::array<std::array<bool, Row>, Col> board;

    constexpr Board()
    {
        auto rand = Random(static_cast<unsigned>(RSEED));
        for (int i = 0; i < Col; ++i) {
            for (int j = 0; j < Row; ++j) {
                board[i][j] = rand.range(0, 2);
            }
        }
    }
    using type = decltype(board);
};

using GameBoard = Board<COL, ROW>;

static constexpr GameBoard generateInitBoard()
{
    return GameBoard{};
}

#endif /* end of include guard: BOARD_H_0MFOR8WC */
