//
// Created by Nikolas on 7/20/17.
//

#ifndef IDONTKNOWCPP_NOTSURE_H
#define IDONTKNOWCPP_NOTSURE_H

#include <array>
#include <string>

class TicTacToe {
private:
	std::array<int, 9> board;
	std::array<char, 9> charBoard;
	int turnNum = 0;
	
	void turn(int player);
	bool checkSlot(int slot);
	bool checkWin();
	void askReplay();
	int oppositePlayer(int player);
	char playerChar(int player);
	void generateBoard();
public:
	TicTacToe();
	void start();
};


#endif //IDONTKNOWCPP_NOTSURE_H
