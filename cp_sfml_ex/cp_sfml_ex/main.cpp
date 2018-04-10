#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Texture t1;
	t1.loadFromFile("images/hills_2018.png");

	sf::Sprite bg;
	bg.setTexture(t1);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.draw(bg);
		window.display();
	}
	return 0;
}
