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
	console("It's your turn, Player " + std::to_string(player) + ". Choose which slot number you would like to use. (You are " + playerChar(player) + ")");
	
	int slot;
	std::cin >> slot;
	
	if (slot < 1 || slot > 9) {
		console("That's not a valid slot number.");
		return turn(player);
	}
	
	if (checkSlot(slot)) {
		console("That slot is already taken.");
		return turn(player);
	}
	
	board[slot - 1] = player;
	
	++turnNum;
	
	console("The current board is:");
	generateBoard();
	
	if (checkWin()) {
		console("Player " + std::to_string(player) + " has won! Would you like a rematch? <true/false>");
		
		return askReplay();
	}
	
	if (turnNum == 9) {
		console("The game has met a tie! Would you like a rematch? <true/false>");
		
		return askReplay();
	}
	
	turn(oppositePlayer(player));
}

bool TicTacToe::checkSlot(int slot) {
	return board[slot - 1] != 0;
}

bool TicTacToe::checkWin() {
	std::array<std::array<int, 3>, 3> rows;
	std::array<std::array<int, 3>, 3> columns;
	std::array<std::array<int, 3>, 2> diagonals;
	
	diagonals[0] = {board[2], board[4], board[6]};
	diagonals[1] = {board[0], board[4], board[8]};
	
	for (int i = 0; i < 3; ++i) {
		rows[0][i] = board[i];
		rows[1][i] = board[i + 3];
		rows[2][i] = board[i + 6];
		columns[i] = {board[i], board[i + 3], board[i + 6]};
	}
	
	bool won = false;
	
	for (int i = 0; i < 3; ++i) { // rows
		if (rows[i][0] == rows[i][1] && rows[i][1] == rows[i][2] && rows[i][2] == rows[i][0]) won = true;
	}
	
	for (int i = 0; i < 3; ++i) { // columns
		if (columns[i][0] == columns[i][1] && columns[i][1] == columns[i][2] && columns[i][2] == columns[i][0]) won = true;
	}
	
	for (int i = 0; i < 2; ++i) { // diagonals
		if (diagonals[i][0] == diagonals[i][1] && diagonals[i][1] == diagonals[i][2] && diagonals[i][2] == diagonals[i][0]) won = true;
	}
	
	return won;
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
