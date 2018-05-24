#include "Block.h"
#include "Console.h"

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
	x = 10, y = 10;
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

void Block::move(int dx)
{
	x += dx;
}

void Block::moveDown()
{
	y++;
}
