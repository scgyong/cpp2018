#pragma once
#include "Scene.h"
class GameScene :
	public Scene
{
public:
	GameScene(RenderWindow &window);
	virtual ~GameScene();

	virtual void update();
	virtual void draw();
};

