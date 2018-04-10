#pragma once
#include <iostream>
using namespace std;

class Circle
{
private:
	int x, y, radius;
	string color;
public:
	Circle(int _x, int _y, int _radius, string _color);
	~Circle();

	void setCenter(int _x, int _y);

	void draw();
	void move();
};

