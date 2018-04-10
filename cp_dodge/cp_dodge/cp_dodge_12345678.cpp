#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define BULLET_COUNT 50

class GameObject {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u size;
public:
	GameObject(const char *filename) {
		texture.loadFromFile(filename);
		sprite.setTexture(texture);
		size = texture.getSize();
	}

	void move() {}

	void draw(sf::RenderWindow &window)
	{
		window.draw(sprite);
	}
};

class Player : public GameObject
{
public:
	Player() : GameObject("images/player.png")
	{
	}
	void move()
	{
		auto pos = sprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (pos.x>0)
				sprite.move(-1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (pos.x<WINDOW_WIDTH - size.x)
				sprite.move(1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (pos.y>0)
				sprite.move(0, -1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (pos.y<WINDOW_HEIGHT - size.y)
				sprite.move(0, 1);
		}
	}
};

class Bullet : public GameObject {
	float dx, dy;
public:
	Bullet() : GameObject("images/missile.png")
	{
		init();
	}
	void init() {
		float x, y;
		int v = rand() % 4;
		switch (v) {
		case 0: //상단
			x = rand() % WINDOW_WIDTH;
			y = -(int)size.y / 2;
			break;
		case 1: //하단
			x = rand() % WINDOW_WIDTH;
			y = WINDOW_HEIGHT - (int)size.y / 2;
			break;
		case 2: //좌측
			x = -(int)size.x / 2;
			y = rand() % WINDOW_HEIGHT;
			break;
		case 3: //우측
			x = WINDOW_WIDTH - (int)size.x / 2;
			y = rand() % WINDOW_HEIGHT;
			break;
		}
		sprite.setPosition(x, y);

		dx = (rand() % 2000 / 1000.0) - 1.0;
		dy = (rand() % 2000 / 1000.0) - 1.0;
	}
	void move() {
		sprite.move(dx, dy);
		auto pos = sprite.getPosition();
		if ((pos.x < 0 - (int)size.x) ||
			(pos.y < 0 - (int)size.y) ||
			(pos.x > WINDOW_WIDTH) ||
			(pos.y > WINDOW_HEIGHT))
		{
			init();
		}
	}
};

void main()
{
	srand((unsigned)time(NULL));

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Dodge Game");

	GameObject bg("images/background.png");

	Player player;
	Bullet bullets[BULLET_COUNT];

	int dx = 1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.move();
		for (auto &b : bullets) {
			b.move();
		}

		window.clear();

		bg.draw(window);
		player.draw(window);
		for (auto &b : bullets) {
			b.draw(window);
		}

		window.display();
	}
}