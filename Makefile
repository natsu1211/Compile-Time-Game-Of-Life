BIN = ./bin/
seed = $(shell date +%s%3)

all:
	mkdir -p $(BIN)
	g++ -std=c++17 -o $(BIN)Main main.cpp -DROW=20 -DCOL=20 -DRSEED=$(seed) -fconstexpr-depth=-1 -fconstexpr-steps=-1
clean:
	rm $(BIN)*
