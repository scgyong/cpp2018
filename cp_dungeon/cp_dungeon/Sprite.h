#pragma once
class Sprite
{
public:
	Sprite(int x, int y, char shape);
	virtual ~Sprite();
	virtual void draw();

	virtual void move(int key);

	friend class Board;

protected:
	int x, y; // current location
	char shape;
};

