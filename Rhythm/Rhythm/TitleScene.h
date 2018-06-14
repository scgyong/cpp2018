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
	int selectedSongIndex;
	Text titleText;
public:
	TitleScene(RenderWindow &window);
	virtual ~TitleScene();

	virtual void update();
	virtual void draw();
	virtual void handleEvent(Event &event);
};

