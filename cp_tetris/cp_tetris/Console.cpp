#include <Windows.h>
#include <iostream>
#include "Console.h"
#include "SFML/Graphics.hpp"

#define WINDOW_WIDTH  300
#define WINDOW_HEIGHT 600

using namespace sf;

static RenderWindow *window = NULL;
static int xCursor = 0, yCursor = 0;
static Sprite blockImage;
static Texture blockTexture;

Console::Console()
{
}


Console::~Console()
{
}

/*
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
*/


void Console::init()
{
	window = new RenderWindow(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Tetris");
	window->setFramerateLimit(60);

	blockTexture.loadFromFile("res/tetris_bits.png");
	blockImage.setTexture(blockTexture);
}

void Console::destroy()
{
	delete window;
}

void Console::clear(char fill)
{
}

int Console::getch()
{
	if (!window->isOpen()) {
		return 'q';
	}

	int key = 0;
	Event event;
	while (window->pollEvent(event)) {
		//char buf[100];
		//wsprintfA(buf, "%d : %d\n", event.type, event.key.code);
		//OutputDebugStringA(buf);
		if (event.type == Event::Closed) {
			window->close();
		} else if (event.type == Event::KeyPressed) {
			if (event.key.code >= Keyboard::A &&
				event.key.code <= Keyboard::Z)
			{
				key = 'a' + (int)event.key.code;
			}
		}
	}
	
	return key;
}

int Console::peekKey()
{
	return 0;
}

void Console::setCursor(int x, int y)
{
	xCursor = x;
	yCursor = y;
}

void Console::putChar(char ch)
{
	if (ch == ' ' || ch == 'O') {
		Color color = ch == ' ' ? Color::Black : Color::White;
		RectangleShape rect(Vector2f(30, 30));
		rect.setPosition(xCursor * 30, yCursor * 30);
		rect.setFillColor(color);
		window->draw(rect);
	} else if (ch >= '1' && ch <= '7') {
		int index = ch - '1';
		IntRect rect(index * 30, 0, 30, 30);
		blockImage.setTextureRect(rect);
		blockImage.setPosition(xCursor * 30, yCursor * 30);
		window->draw(blockImage);
	}

	xCursor++;
}

void Console::sleep(int msec)
{
	Sleep(msec);
}

int Console::getSystemTime()
{
	return (int)GetTickCount();
}

void Console::display()
{
	window->display();
}
