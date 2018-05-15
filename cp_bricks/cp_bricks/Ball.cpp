#include "Ball.h"



Ball::Ball(float x, float y) : CircleShape(12.0)
{
	setPosition(x, y);
	setFillColor(Color(255, 128, 0));
	setOrigin(0, 0);
}


Ball::~Ball()
{
}
