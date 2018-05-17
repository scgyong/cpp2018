#pragma once
#include "Scene.h"
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"

using namespace std;

class GameScene :
	public Scene
{
	Paddle paddle;
	Ball ball;
	vector<Brick> bricks;

public:
	GameScene(RenderWindow &window);
	virtual ~GameScene();

	virtual void update();
	virtual void draw();
};

