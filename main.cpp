/* ------------------------------
# author  : natsu1211
# date    : 2018-09-14
------------------------------- */
#define RUNTIME 0

#if RUNTIME
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#endif
#include "const_string.h"
#include "board.h"
#include "engine.h"
#include "printer.h"


int main(int argc, char* argv[]) {
#if RUNTIME
    Engine engine(generateInitBoard());
    for (int i = 0; i < 100; ++i) {
        system("clear"); // system is danger!
        //std::cout << std::string(100, '\n'); //simple and safe clear
        std::cout << "Generation: " << i+1 << '\n';
        const auto& nextEngine = engine.update();
        Printer<GameBoard>::print(nextEngine.getBoard());
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
#else
    constexpr auto nextEngine = Engine(generateInitBoard()).update();
    Printer<GameBoard>::print(nextEngine.getBoard()); //runtime io
#endif
    return 0;
}
