//#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "main.h"

using namespace sf;

GameScene::GameScene() :
	ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)
{
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 10; x++) {
			Brick brick(
				(float)(x * (60 + 3) + 20), 
				(float)(y * (20 + 3) + 40)
			);
			bricks.push_back(brick);
		}
	}
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
	for (auto &b : bricks) {
		window.draw(b);
	}
}
