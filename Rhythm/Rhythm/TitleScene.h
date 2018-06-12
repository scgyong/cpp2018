#pragma once
#include "Scene.h"
#include <vector>

using namespace std;
class Song;

class TitleScene :
	public Scene
{
	//vector<Song *> songs;
	//void loadSongs();
public:
	TitleScene(RenderWindow &window);
	virtual ~TitleScene();

	virtual void update();
	virtual void draw();
};

