#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball :
	public CircleShape
{
	Vector2f speed;

public:
	Ball(float x, float y);
	virtual ~Ball();

	void update();
};

