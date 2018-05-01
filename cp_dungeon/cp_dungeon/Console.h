#pragma once
class Console
{
public:
	Console();
	~Console();

	static void clear(char fill = ' ');
	static int getch();
	static void setCursor(int x, int y);
};

