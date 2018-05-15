#include "Ball.h"

#define BALL_SPEED_DX 5.0
#define BALL_SPEED_DY 5.0


Ball::Ball(float x, float y) : 
	CircleShape(12.0),
	speed(BALL_SPEED_DX, BALL_SPEED_DY)
{
	setPosition(x, y);
	setFillColor(Color(255, 128, 0));
	setOrigin(0, 0);
}


Ball::~Ball()
{
}

void Ball::update()
{
	move(speed);
}
