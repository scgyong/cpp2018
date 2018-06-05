#include "TitleScene.h"
#include "GameScene.h"


TitleScene::TitleScene(RenderWindow &window)
	: Scene(window)
{
}


TitleScene::~TitleScene()
{
}

void TitleScene::update()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		GameScene *scene = new GameScene(window);
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
