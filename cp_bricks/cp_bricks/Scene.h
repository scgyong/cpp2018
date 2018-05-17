#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Scene
{
protected:
	RenderWindow &window;
public:
	Scene(RenderWindow &window);
	virtual ~Scene();

	virtual void update() = 0;
	virtual void draw() = 0;
};

