#include "Board.h"
#include "Block.h"
#include "Console.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

Board *Board::s_board;

Board::Board()
{
	s_board = this;

	width = BOARD_WIDTH;
	height = BOARD_HEIGHT;

	const int size = width * height;
	bits = new int[size];
	for (int i = 0; i < size; i++) {
		bits[i] = 0;
	}
}


Board::~Board()
{
	delete[] bits;
}

void Board::plant(Block &block)
{
	for (int i = 0; i < 4; i++) {
		int x = block.points[i].x;
		int y = block.points[i].y;
		int t = block.type;
		bits[y * width + x] = t;
	}
}

void Board::draw()
{
	for (int y = 0; y < height; y++) {
		Console::setCursor(0, y);
		for (int x = 0; x < width; x++) {
			int t = bits[y * width + x];
			char ch = t ? ('0' + t) : ' ';
			Console::putChar(ch);
		}
	}
}

bool Board::isValid(int x, int y)
{
	if (x < 0 || x >= width) return false;
	if (y < 0 || y >= height) return false;

	if (bits[y * width + x] > 0) return false;

	return true;
}

int Board::deleteLines()
{
	int lines = 0;
	// for every lines
	{
		int count = 0;
		// for every x 
		{
			//if (block exists) {
			//	count++;
			//}
		}
		if (count == width) {
			//remove all bits at that line
			//move down all bits above 
			lines++;
		}
	}
	return lines;
}

//Board &Board::get()
//{
//	return *g_board;
//}

//inline int Board::getWidth()
//{
//	return width;
//}
//
//inline int Board::getHeight()
//{
//	return height;
//}
