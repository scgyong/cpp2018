#include "Hero.h"


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
		x--;
		break;
	case 'd':
		x++;
		break;
	case 'w':
		y--;
		break;
	case 's':
		y++;
		break;
	}
}
