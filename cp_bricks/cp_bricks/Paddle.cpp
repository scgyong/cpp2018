#include "Paddle.h"

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
