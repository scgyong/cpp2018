#include <SFML/Graphics.hpp>
#include "GameScene.h"

using namespace sf;

int main(void)
{
	GameScene scene;
	RenderWindow window(VideoMode(800, 600), "Bricks");
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		scene.draw(window);
		window.display();
	}
	return 0;
}

