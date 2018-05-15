#pragma once
#include "Scene.h"

class GameScene :
	public Scene
{
public:
	GameScene();
	virtual ~GameScene();

	virtual void update();
	virtual void draw(RenderWindow &window);
};

