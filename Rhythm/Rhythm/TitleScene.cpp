#include "TitleScene.h"
#include "GameScene.h"
#include "Song.h"
#include "DirUtil.h"

#if 0
void TitleScene::loadSongs()
{
	vector<string> filenames;
	DirUtil::readDir("songs/*.txt", filenames);
	printf("%d files read.", filenames.size());
}
#endif

TitleScene::TitleScene(RenderWindow &window)
	: Scene(window)
{
	// init songs
	Song::loadSongs();
}


TitleScene::~TitleScene()
{
	//for (Song *song : songs) {
	//	delete song;
	//}

	//songs.clear();
}

void TitleScene::update()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		int index = 0;

		Song &song = *Song::songs[index];
		GameScene *scene = new GameScene(window, song);
		changeScene(scene);
	}
	// do nothing
}

void TitleScene::draw()
{
	window.clear(Color::Blue);
	Text text;
	text.setString("Rhythm Game");
	//text.setScale(2.f, 2.f);
	text.setPosition(100.f, 100.f);
	text.setFillColor(Color::White);
	window.draw(text);
}
