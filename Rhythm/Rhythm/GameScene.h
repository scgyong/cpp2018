#pragma once
#include "Scene.h"
#include "Song.h"

class GameScene :
	public Scene
{
	Clock clock;
	Song song;
	bool presseds[6];
public:
	GameScene(RenderWindow &window);
	virtual ~GameScene();

	virtual void update();
	virtual void draw();
	virtual void handleEvent(Event &event);

	void goBackToTitle();
	void handleInput(int position);
};

