#include <iostream>
#include "Board.h"

using namespace std;

#define BLANK_CHAR '.'

Board::Board()
{
	clear();
}


Board::~Board()
{
}

void Board::print()
{
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		cout << '\t';
		for (int x = 0; x < BOARD_WIDTH; x++) {
			cout << board[y][x];
		}
		cout << endl;
	}
}

void Board::clear()
{
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			board[y][x] = BLANK_CHAR;
		}
	}
}

void Board::set(int x, int y, char shape)
{
	if (x < 0 || x >= BOARD_WIDTH || y < 0 || y >= BOARD_HEIGHT) {
		cout << "Error!! x=" << x << " and y=" << y << endl;
		return;
	}
	board[y][x] = shape;
}
