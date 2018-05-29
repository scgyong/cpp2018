#pragma once
class Console
{
public:
	Console();
	~Console();

	static void clear(char fill = ' ');
	static int getch();
	static int peekKey();
	static void setCursor(int x, int y);
	static void putChar(char ch);
	static void sleep(int msec);
};

