#include <Windows.h>
#include "Console.h"


Console::Console()
{
}


Console::~Console()
{
}

void Console::clear(char fill)
{
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}

int Console::getch()
{
	HANDLE rHnd;
	rHnd = GetStdHandle(STD_INPUT_HANDLE);

	INPUT_RECORD rec;
	DWORD num;

	do { ReadConsoleInput(rHnd, &rec, 1, &num); } while (num == 0 || rec.EventType != KEY_EVENT || rec.Event.KeyEvent.bKeyDown == FALSE);

	short rv = rec.Event.KeyEvent.uChar.AsciiChar;

	//if no ascii code detected, return virtual key code (VK_*)
	if (rv == 0) rv = rec.Event.KeyEvent.wVirtualKeyCode;

	return rv;
}

void Console::setCursor(int x, int y)
{
	HANDLE rHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { (short)x, (short)y };
	SetConsoleCursorPosition(rHnd, coord);
}
