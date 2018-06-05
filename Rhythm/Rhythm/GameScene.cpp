#include "GameScene.h"
#include "TitleScene.h"

#define PIXELS_PER_SECOND 500
#define BASE_Y 500

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

	CircleShape circle(20.0f);
	circle.setOrigin(20, 20);
	circle.setFillColor(Color::White);

	float now = (float)clock.getElapsedTime().asSeconds();
	for (auto note : song.notes) {
		float x = (float)(60.0 * note.position);
		float y = PIXELS_PER_SECOND * (now - note.seconds) + BASE_Y;
		circle.setPosition(x, y);
		window.draw(circle);
	}
}
