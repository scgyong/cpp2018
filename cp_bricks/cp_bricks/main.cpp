#include <SFML/Graphics.hpp>
#include "GameScene.h"

using namespace sf;

int main(void)
{
	//GameScene scene;
	Scene *scene = new GameScene();
	RenderWindow window(VideoMode(800, 600), "Bricks");
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		scene->update();
		scene->draw(window);
		window.display();
	}

	delete scene;

	return 0;
}

