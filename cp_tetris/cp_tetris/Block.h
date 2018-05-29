#pragma once


class Block
{
	class Point {
	public:
		int x, y;
	};
	int type; // 1 = ¤¡, 2 = ¤¤, ...
	Point points[4];
	//int x, y;
public:
	Block();
	virtual ~Block();
	void init(int type, int x, int y);
	void draw();
	bool move(int dx);
	bool moveDown();
	bool rotate();
};

