//#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "main.h"

using namespace sf;

GameScene::GameScene() :
	ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)
{
}


GameScene::~GameScene()
{
}

void GameScene::update()
{
	ball.update();
}

void GameScene::draw(RenderWindow &window)
{
	window.clear(Color::Blue);
	window.draw(ball);
}
