#pragma once
#include "Scene.h"
#include "Ball.h"
#include "Brick.h"

using namespace std;

class GameScene :
	public Scene
{
	Ball ball;
	vector<Brick> bricks;

public:
	GameScene();
	virtual ~GameScene();

	virtual void update();
	virtual void draw(RenderWindow &window);
};

