#pragma once
#include "Scene.h"
class TitleScene :
	public Scene
{
public:
	TitleScene(RenderWindow &window);
	virtual ~TitleScene();

	virtual void update();
	virtual void draw();
};

