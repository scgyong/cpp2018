#include "Coord.h"

float Coord::x(int line)
{
	float x = LEFT_MARGIN + line * NOTE_WIDTH;
	if (line >= 4) {
		x += CENTER_MARGIN;
	}
	return x;
}

float Coord::y(float seconds)
{
	float y = PIXELS_PER_SECOND * seconds + BASE_Y;
	return y;
}
