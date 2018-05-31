#include <Windows.h>
#include <iostream>
#include "Console.h"
#include "SFML/Graphics.hpp"

#define WINDOW_WIDTH  300
#define WINDOW_HEIGHT 600

using namespace sf;

static RenderWindow *window = NULL;
static int xCursor = 0, yCursor = 0;

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
	Color color;
	if (ch == ' ') {
		color = Color::Black;
	} else if (ch == 'O') {
		color = Color::White;
	} else if (ch >= '1' && ch <= '7') {
		static Color colors[] = {
			Color::Blue,
			Color::Cyan,
			Color::Green,
			Color::Yellow,
			Color::Magenta,
			Color::Red,
			Color(0xFF7733FF)
		};
		color = colors[ch - '1'];
	}
	RectangleShape rect(Vector2f(30, 30));
	rect.setPosition(xCursor * 30, yCursor * 30);
	rect.setFillColor(color);
	window->draw(rect);

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
