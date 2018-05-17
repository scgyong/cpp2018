#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "main.h"

using namespace sf;

int main(void)
{
	//GameScene scene;
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Bricks");
	Scene *scene = new GameScene(window);
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		scene->update();
		scene->draw();
		window.display();
	}

	delete scene;

	return 0;
}

