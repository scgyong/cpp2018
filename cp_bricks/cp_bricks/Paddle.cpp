#include "Paddle.h"

#define PADDLE_WIDTH 80.0
#define PADDLE_HEIGHT 20.0

Paddle::Paddle(float x, float y)
{
	setPosition(x, y);
	setSize({ PADDLE_WIDTH, PADDLE_HEIGHT });
	setOrigin(0, 0);
	setFillColor(Color(0, 255, 64));
}


Paddle::~Paddle()
{
}

void Paddle::update(float x)
{
	auto pos = getPosition();
	pos.x = x;
	setPosition(pos);
}
