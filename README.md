# Compile-Time-Game-Of-Life
Compile time [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) written in C++17. Inspired by Jean's [meta_crush_saga](https://jguegant.github.io/blogs/tech/meta-crush-saga.html).     
Notice this implementation is mainly based on `constexpr`, if you want to do this in a more TMP way, see this amazing [post](https://blog.mattbierner.com/stupid-template-tricks-super-template-tetris/).     
The main difference is that Conway's Game of Life is not really an interactive game, which means the next game state can be determined by current state. So there is no need to serialize the game state and receive user's input.

## Usage
Clone this repo, then
```
make
cd bin
./Main
```
You can modify `-DCOL` and `-DROW` compile flag in `Makefile` to resize board, which will become macro definitions `COL` and `ROW`.     
Also change `STEPS` variable in `main.cpp` to set the simulation step, the default value of which is 100.     

Define `RUNTIME` to `0` or `1` to make simulation run at compile-time or run-time.
You can see output at console, refreshed at every 0.3 second.     

