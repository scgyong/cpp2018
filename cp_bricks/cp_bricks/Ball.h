#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball :
	public CircleShape
{
public:
	Ball(float x, float y);
	virtual ~Ball();
};

