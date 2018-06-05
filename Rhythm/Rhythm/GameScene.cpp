#include "GameScene.h"
#include "TitleScene.h"


GameScene::GameScene(RenderWindow &window)
	: Scene(window)
{
	song.load("song_1.txt");
	clock.restart();
}


GameScene::~GameScene()
{
}

void GameScene::update()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
		Scene *scene = new TitleScene(window);
		changeScene(scene);
	}
}

void GameScene::draw()
{
	window.clear(Color::Red);
	Text text;
	text.setString("In Game");
	//text.setScale(2.f, 2.f);
	text.setPosition(100.f, 100.f);
	text.setFillColor(Color::White);
	window.draw(text);

	//double now = clock.getElapsedTime().asSeconds();
	//for (auto note : song.notes) {
	//	double diff = note.seconds
	//}
}
