#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void draw(RenderWindow &window) = 0;
};

