#pragma once
class Sprite
{
public:
	Sprite(int x, int y, char shape);
	virtual ~Sprite();
	virtual void draw();

protected:
	int x, y; // current location
	char shape;
};

