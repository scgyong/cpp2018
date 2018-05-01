#pragma once

#define BOARD_WIDTH  40
#define BOARD_HEIGHT 20

class Board
{
	char board[BOARD_HEIGHT][BOARD_WIDTH];
public:
	Board();
	~Board();

	void print();
	void clear();
	void set(int x, int y, char shape);
};

