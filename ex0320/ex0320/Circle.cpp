#include <Windows.h>
#include "Circle.h"

Circle::Circle(int _x, int _y, int _radius, string _color)
	: x(_x), y(_y), radius(_radius), color(_color)
{
}

Circle::~Circle()
{
}

void Circle::setCenter(int _x, int _y)
{
	if (_x >= 0 && _y >= 0) {
		x = _x;
		y = _y;
	}
}

void Circle::draw() {
	HDC hdc = GetWindowDC(GetForegroundWindow());
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
}


void Circle::move()
{
	x += rand() % 50;
}
