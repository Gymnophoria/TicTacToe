#include <iostream>
#include "TicTacToe.h"
#include "functions.h"

int main() {
    console("Tic-Tac-Toe has started. Game is setup as follows:\n1 |2 |3\n--|--|--\n4 |5 |6\n--|--|--\n7 |8 |9");
	
	TicTacToe game;
	game.start();
	
    return 0;
}