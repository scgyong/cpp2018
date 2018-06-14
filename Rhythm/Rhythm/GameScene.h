#pragma once
#include "Scene.h"
#include "Song.h"

class GameScene :
	public Scene
{
	Clock clock;
	Song &song;
	bool presseds[6];
	int score;
	Text scoreText;
	Text judgeText;
	float judgeDisappearTime;

public:
	GameScene(RenderWindow &window, Song &song);
	virtual ~GameScene();

	virtual void update();
	virtual void draw();
	virtual void handleEvent(Event &event);

	void goBackToTitle();
	void handleInput(int position);
	void setJudgeText(const char *text);
	void addScore(int score);
};

