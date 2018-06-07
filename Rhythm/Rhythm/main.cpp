#include <SFML/Graphics.hpp>
#include "TitleScene.h"
#include "main.h"

using namespace sf;

int main(void)
{
	//GameScene scene;
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Rhythm");
	Scene::changeScene(new TitleScene(window));

	window.setFramerateLimit(60);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				continue;
			}
			Scene::getCurrentScene()->handleEvent(event);
		}
		Scene::getCurrentScene()->update();
		Scene::getCurrentScene()->draw();
		window.display();
	}

	Scene::changeScene(NULL);
	//delete Scene::getCurrentScene();

	return 0;
}

