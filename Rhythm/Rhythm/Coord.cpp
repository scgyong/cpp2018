#include "Coord.h"

float Coord::x(int line)
{
	return line * 60;
}

float Coord::y(float seconds)
{
	float y = PIXELS_PER_SECOND * seconds + BASE_Y;
	return y;
}
