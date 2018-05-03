#include <iostream>
#include "Sprite.h"
using namespace std;

Sprite::Sprite(int x, int y, char shape)
	: x(x), y(y), shape(shape)
{
	//this->x = x;
	//this->y = y;
	//this->shape = shape;
}

Sprite::~Sprite()
{
}

void Sprite::draw()
{
	cout << shape;
}

void Sprite::move(int key)
{
	// do nothing.
}
