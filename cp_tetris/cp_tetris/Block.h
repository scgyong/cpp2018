#pragma once



class Block
{
	int type; // 1 = ¤¡, 2 = ¤¤, ...
	int x, y;
public:
	Block();
	virtual ~Block();

	void draw();
	bool move(int dx);
	bool moveDown();
};

