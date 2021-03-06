#pragma once

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define NOTE_WIDTH   60
#define NOTE_RADIUS  20

#define PIXELS_PER_SECOND 500
#define BASE_Y            500
#define BASELINE_HEIGHT     3
#define VLINE_WIDTH        10

#define LEFT_MARGIN   30
#define CENTER_MARGIN 50

#define SCORETEXT_X 500
#define SCORETEXT_Y  80

#define JUDGETEXT_X 100
#define JUDGETEXT_Y 150

class Coord
{
public:
	static float x(int line);
	static float y(float seconds);
};

