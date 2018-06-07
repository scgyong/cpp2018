#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Scene
{
protected:
	RenderWindow &window;
	static Scene *currentScene;
public:
	Scene(RenderWindow &window);
	virtual ~Scene();

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void handleEvent(Event &event) {}

	static void changeScene(Scene *scene);
	static Scene *getCurrentScene() { return currentScene; }
};

