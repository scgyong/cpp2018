#include "Ball.h"
#include "main.h"

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
	auto pos = getPosition();
	if (pos.x < 0) {
		speed.x = abs(speed.x);
	} else if (pos.x > WINDOW_WIDTH) {
		speed.x = -abs(speed.x);
	}

	if (pos.y < 0) {
		speed.y = abs(speed.y);
	} else if (pos.y > WINDOW_HEIGHT) {
		speed.y = -abs(speed.y);
	}
}
