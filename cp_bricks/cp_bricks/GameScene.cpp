//#include <SFML/Graphics.hpp>
#include "GameScene.h"

using namespace sf;

GameScene::GameScene() : ball(400, 300)
{
}


GameScene::~GameScene()
{
}

void GameScene::update()
{
	//ball.update();
}

void GameScene::draw(RenderWindow &window)
{
	window.clear(Color::Blue);
	window.draw(ball);
}
