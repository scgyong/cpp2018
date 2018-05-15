#pragma once
#include "Scene.h"
#include "Ball.h"

class GameScene :
	public Scene
{
	Ball ball;

public:
	GameScene();
	virtual ~GameScene();

	virtual void update();
	virtual void draw(RenderWindow &window);
};

