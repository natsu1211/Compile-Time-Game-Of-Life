/* ------------------------------
# author  : natsu1211
# date    : 2018-09-16
------------------------------- */

#ifndef PRINTER_H_QIOBDHFR
#define PRINTER_H_QIOBDHFR
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>
#include "board.h"

template<typename T>
struct Printer
{
    static void print(T board, int i = 0)
    {
        system("clear"); // system is danger!
        //std::cout << std::string(100, '\n'); //simple and safe clear
        std::cout << "Generation: " << i+1 << '\n';
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
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
};

#endif /* end of include guard: PRINTER_H_QIOBDHFR */
