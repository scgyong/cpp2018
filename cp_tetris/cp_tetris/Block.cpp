#include "Block.h"
#include "Console.h"
#include "Board.h"

// ぁ, い, た, s, z, け, 1, 

// 01
// 23
// 45
// 67
// ぁ = 0, 1, 3, 5
// い = 0, 2, 4, 5

static int coords[][4] = {
	{ 0, 1, 3, 5 }, // ぁ
	{ 0, 2, 4, 5 }, // い
	{ 0, 2, 3, 4 }, // た
	{ 0, 3, 4, 5 }, // s
	{ 1, 2, 3, 4 }, // z
	{ 0, 1, 2, 3 }, // け
	{ 0, 2, 4, 6 } // 1
};

Block::Block()
{
	type = 1;
	x = 0, y = 0;
}


Block::~Block()
{
}

// 01
// 23
// 45
// 67

void Block::draw()
{
	for (int i = 0; i < 4; i++) {
		int v = coords[type - 1][i];
		int dx = v % 2;
		int dy = v / 2;
		Console::setCursor(x + dx, y + dy);
		Console::putChar('O');
	}
}

bool Block::move(int dx)
{
	int width = Board::get().getWidth();

	for (int i = 0; i < 4; i++) {
		int v = coords[type - 1][i];
		int nx = x + v % 2 + dx;
		//int ny = y + v / 2;

		if (nx < 0 || nx >= width) {
			return false;
		}
	}

	x += dx;
	return true;
}

bool Block::moveDown()
{
	int height = Board::get().getHeight();

	for (int i = 0; i < 4; i++) {
		int v = coords[type - 1][i];
		//int nx = x + v % 2;
		int ny = y + v / 2 + 1;

		if (ny >= height) {
			return false;
		}
	}

	y++;
	return true;
}
