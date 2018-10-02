/* ------------------------------
# author  : natsu1211
# date    : 2018-09-15
------------------------------- */

#ifndef ENGINE_H_JXB8MVTF
#define ENGINE_H_JXB8MVTF
#include "board.h"

class Engine
{
    public:
        constexpr Engine()
            :board_{}
        {
        }

        constexpr Engine(const GameBoard& board)
            :board_(board)
        {
        }

        constexpr auto update()
        {
            auto b = board_;
            for (int i = 0; i < COL; ++i) {
                for (int j = 0;  j < ROW; ++j) {
                    int aliveAround = aliveCount(j, i);
                    if(board_[i][j]) //alive
                    {
                        if(aliveAround < 2 )
                        {
                            //under population
                            b[i][j] = false;
                        }
                        else if(aliveAround == 2 || aliveAround == 3)
                        {
                            //next generation
                        }
                        else if(aliveAround > 3)
                        {
                            //over population
                            b[i][j] = false;
                        }
                    }
                    else //dead
                    {
                        if(aliveAround == 3)
                        {
                            //reproduction
                            b[i][j] = true;
                        }
                    }
                }
            }
            board_ = b;
            return *this;
        }

        constexpr const GameBoard& getBoard() const
        {
            return board_;
        }

    private:
        GameBoard board_;
        constexpr bool InBoard(int x, int y) const
        {
            if (x < ROW && x >= 0 && y < COL && y >=0) {
                return true;
            }
            return false;
        }

        constexpr int aliveCount(int x, int y) const
        {
            int count = 0;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1;  j <= 1; ++j) {
                    if((i != 0 || j != 0) && InBoard(x+i, y+j))
                    {
                        if(board_[y+j][x+i])
                        {
                            ++count;
                        }
                    }
                }
            }
            return count;
        }

};



#endif /* end of include guard: ENGINE_H_JXB8MVTF */

