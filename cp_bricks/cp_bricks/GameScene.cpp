//#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "main.h"

#define PADDLE_Y_OFFSET 50.0

using namespace sf;

GameScene::GameScene(RenderWindow &window) :
	Scene(window),
	ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
	paddle(WINDOW_WIDTH / 2, WINDOW_HEIGHT - PADDLE_Y_OFFSET)
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
	Vector2i mousePos = Mouse::getPosition(window);
	float x = mousePos.x;
	if (x < 0) {
		x = 0;
	} else if (x > WINDOW_WIDTH - PADDLE_WIDTH ) {
		x = WINDOW_WIDTH - PADDLE_WIDTH;
	}
	paddle.update(x);
	ball.update();

	if (ball.collides(paddle)) {
		ball.bounceUp();
	}
}

void GameScene::draw()
{
	window.clear(Color::Blue);
	window.draw(ball);
	for (auto &b : bricks) {
		window.draw(b);
	}
	window.draw(paddle);
}
