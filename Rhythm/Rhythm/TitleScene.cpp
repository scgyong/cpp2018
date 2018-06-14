#include "TitleScene.h"
#include "GameScene.h"
#include "Song.h"
#include "DirUtil.h"
#include "Fonts.h"

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
	selectedSongIndex = 0;
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

		Song &song = *Song::songs[selectedSongIndex];
		GameScene *scene = new GameScene(window, song);
		changeScene(scene);
	}
	// do nothing
}

void TitleScene::draw()
{
	Song &song = *Song::songs[selectedSongIndex];

	window.clear(Color::Blue);
	Text text;
	text.setString(song.title);
	text.setFont(Fonts::fonts.def);
	//text.setScale(2.f, 2.f);
	text.setPosition(100.f, 100.f);
	text.setFillColor(Color::White);


	window.draw(text);
}

void TitleScene::handleEvent(Event & event)
{
	if (event.type != Event::KeyPressed) {
		return;
	}

	int delta = 0;
	switch (event.key.code) {
	case Keyboard::Left:
		delta = -1;
		break;
	case Keyboard::Right:
		delta = 1;
		break;
	default:
		return;
	}
	int count = Song::songs.size();
	selectedSongIndex = (selectedSongIndex + delta + count) % count;
}
