#pragma once
#include <SFML/Graphics.hpp>

#define PADDLE_WIDTH 80.0
#define PADDLE_HEIGHT 20.0

using namespace sf;

class Paddle :
	public RectangleShape
{
public:
	Paddle(float x, float y);
	virtual ~Paddle();

	void update(float x);
};

