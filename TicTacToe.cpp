//
// Created by Nikolas on 7/20/17.
//

#include "TicTacToe.h"
#include "functions.h"
#include <iostream>

TicTacToe::TicTacToe() {
	board = {0, 0, 0, 0, 0, 0, 0, 0, 0};
}

void TicTacToe::turn(int player) {
	console("It's your turn, Player " + std::to_string(player) + ". Choose which slot number you would like to use. (You are x)");
	
	int slot;
	std::cin >> slot;
	
	if (slot < 1 || slot > 10) {
		console("That's not a valid slot number.");
		return turn(player);
	}
	
	if (checkSlot(slot)) {
		console("That slot is already taken.");
		return turn(player);
	}
	
	board[slot - 1] = player;
	
	++turnNum;
	
	if (checkWin()) {
		console("Player " + std::to_string(player) + " has won! Would you like a rematch? <true/false>");
		
		return askReplay();
	}
	
	if (turnNum == 9) {
		console("The game has met a tie! Would you like a rematch? <true/false>");
		
		return askReplay();
	}
	
	console("The current board is:");
	generateBoard();
	
	turn(oppositePlayer(player));
}

bool TicTacToe::checkSlot(int slot) {
	return board[slot] != 0;
}

bool TicTacToe::checkWin() {
	return false;
}

void TicTacToe::start() {
	board = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	turnNum = 0;
	turn(1);
}

void TicTacToe::askReplay() {
	bool leave;
	std::cin >> leave;
	
	if (leave) {
		start();
	} else {
		console("See you next time!");
		std::exit(69);
	}
}

int TicTacToe::oppositePlayer(int player) {
	if (player == 1) return 2;
	return 1;
}

void TicTacToe::generateBoard() {
	for (int i = 0; i < 9; ++i) {
		charBoard[i] = playerChar(board[i]);
	}
	
	printf("%c |%c |%c\n--|--|--\n%c |%c |%c\n--|--|--\n%c |%c |%c\n", charBoard[0], charBoard[1], charBoard[2], charBoard[3], charBoard[4], charBoard[5], charBoard[6], charBoard[7], charBoard[8]);
}

char TicTacToe::playerChar(int player) {
	if (player == 0) return ' ';
	if (player == 1) return 'x';
	return 'o';
}
