#include <SFML/Graphics.hpp>

using namespace sf;

int main(void)
{
	RenderWindow window(VideoMode(800, 600), "Bricks");
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		window.display();
	}
	return 0;
}

