#include "Ball.h"
#include "main.h"

#define BALL_SPEED_DX 5.0
#define BALL_SPEED_DY 5.0
#define BALL_RADIUS 12.0


Ball::Ball(float x, float y) : 
	CircleShape(BALL_RADIUS),
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
	} else if (pos.x > WINDOW_WIDTH - 2 * BALL_RADIUS) {
		speed.x = -abs(speed.x);
	}

	if (pos.y < 0) {
		speed.y = abs(speed.y);
	} else if (pos.y > WINDOW_HEIGHT - 2 * BALL_RADIUS) {
		speed.y = -abs(speed.y);
	}
}

bool Ball::collides(Shape &shape)
{
	auto myBounds = getGlobalBounds();
	auto shapeBounds = shape.getGlobalBounds();
	return myBounds.intersects(shapeBounds);
}

void Ball::bounceUp()
{
	speed.y = -abs(speed.y);
}
