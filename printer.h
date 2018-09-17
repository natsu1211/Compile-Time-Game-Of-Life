/* ------------------------------
# author  : natsu1211
# date    : 2018-09-16
------------------------------- */

#ifndef PRINTER_H_QIOBDHFR
#define PRINTER_H_QIOBDHFR
#include "board.h"
#include <iostream>

template<typename T>
struct Printer
{
    static void print(T board)
    {
        std::cout << "--------------------------------------------" << '\n';
        for(auto& row : board)
        {
            std::cout << "| ";
            for(auto b : row)
            {
                std::cout << (b ? "O" : " ") << " ";
            }
            std::cout << " |" << '\n';
        }
        std::cout << "--------------------------------------------" << std::endl;
    }
};

#endif /* end of include guard: PRINTER_H_QIOBDHFR */
