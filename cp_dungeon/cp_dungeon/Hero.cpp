#include "Hero.h"
#include "Board.h"

Hero::Hero(int x, int y) : Sprite(x, y, 'H')
{
}

Hero::~Hero()
{
}

void Hero::move(int key)
{
	switch (key) {
	case 'a':
		// Early Return
		if (x <= 0) {
			throw 0;
		}
		x--;
		break;
	case 'd':
		if (x >= BOARD_WIDTH - 1) {
			throw 0;
		}
		x++;
		break;
	case 'w':
		if (y <= 0) {
			throw 0;
		}
		y--;
		break;
	case 's':
		if (y >= BOARD_HEIGHT - 1) {
			throw 0;
		}
		y++;
		break;
	}
}
