#pragma once
#include "Scene.h"
#include "Song.h"

class GameScene :
	public Scene
{
	Clock clock;
	Song song;
public:
	GameScene(RenderWindow &window);
	virtual ~GameScene();

	virtual void update();
	virtual void draw();
};

