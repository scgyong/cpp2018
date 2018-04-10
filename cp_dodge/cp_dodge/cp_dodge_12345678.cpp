#include <SFML/Graphics.hpp>
#define WINDOW_WIDTH 800
#define WINDOW_HIGHT 600
class player
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u size;
	//int dx;
public:
	player()
	{
		texture.loadFromFile("images/player.png");
		sprite.setTexture(texture);
		size = texture.getSize();
		//dx = 1;
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
			if (pos.y<WINDOW_HIGHT - size.y)
				sprite.move(0, 1);
		}
	}
	void draw(sf::RenderWindow &window)
	{
		window.draw(sprite);
	}
};

void main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "Dodge Game");

	sf::Texture bgTexture;
	bgTexture.loadFromFile("images/background.png");
	sf::Sprite bgSprite;
	bgSprite.setTexture(bgTexture);

	//sf::Texture playerTexture;
	//playerTexture.loadFromFile("images/player.png");

	//sf::Sprite playerSprite;
	//playerSprite.setTexture(playerTexture);


	player player;

	int dx = 1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		/*playerSprite.move(dx, 0);
		sf::Vector2f pos = playerSprite.getPosition();
		if (pos.x > 800) { dx = -1; }
		else if (pos.x < 0) { dx = 1; }*/

		player.move();

		window.clear();
		window.draw(bgSprite);
		//window.draw(playerSprite);
		player.draw(window);
		window.display();
	}
}