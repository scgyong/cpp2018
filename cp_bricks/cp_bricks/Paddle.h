#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle :
	public RectangleShape
{
public:
	Paddle(float x, float y);
	virtual ~Paddle();

	void update(float x);
};

