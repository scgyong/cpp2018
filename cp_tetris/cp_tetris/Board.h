#pragma once

#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Block;

class Board
{
	static Board *s_board;
	int width, height;
	int *bits;
public:
	Board();
	virtual ~Board();

	inline static Board &get() { return *s_board;  }
	inline int getWidth() { return width; }
	inline int getHeight() { return height; }

	void plant(Block &block);
	void draw();
	bool isValid(int x, int y);
	int deleteLines();
};

