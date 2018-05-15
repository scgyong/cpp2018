#pragma once
#include "Scene.h"
#include "Ball.h"

class GameScene :
	public Scene
{
public:
	GameScene();
	virtual ~GameScene();

	Ball ball;

	virtual void update();
	virtual void draw(RenderWindow &window);
};

