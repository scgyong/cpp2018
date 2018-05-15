#include "Brick.h"

#define BRICK_SIZE_W 60.0
#define BRICK_SIZE_H 20.0

Brick::Brick(float x, float y)
{
	setPosition(x, y);
	setSize({ BRICK_SIZE_W, BRICK_SIZE_H });
	setFillColor(Color::Yellow);
	setOrigin(0, 0);
}


Brick::~Brick()
{
}
