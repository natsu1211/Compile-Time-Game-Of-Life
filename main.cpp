/* ------------------------------
# author  : natsu1211
# date    : 2018-09-14
------------------------------- */
#define RUNTIME 0

#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include "const_string.h"
#include "board.h"
#include "engine.h"
#include "printer.h"
#include "util.h"

int main(int argc, char* argv[]) {
    constexpr std::size_t STEPS = 100; //simulation steps
#if RUNTIME
    Engine engine(generateInitBoard());
    for (int i = 0; i < STEPS; ++i) {
        system("clear"); // system is danger!
        //std::cout << std::string(100, '\n'); //simple and safe clear
        const auto& nextEngine = engine.update();
        Printer<GameBoard>::print(nextEngine.getBoard(), i);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
#else
    constexpr auto engine = Engine(generateInitBoard());
    constexpr auto t = to_tuple<STEPS>::apply(engine);
    for_each_tuple<Printer>(t);
#endif
    return 0;
}
