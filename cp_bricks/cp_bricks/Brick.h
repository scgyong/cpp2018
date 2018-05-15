#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Brick :
	public RectangleShape
{
public:
	Brick(float x, float y);
	virtual ~Brick();
};

