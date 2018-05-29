#include <Windows.h>
#include <iostream>
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

int Console::peekKey()
{
	MSG msg;

	while (1) {
		if (!PeekMessage(&msg, NULL, 0, 0, 0)) {
			OutputDebugStringA("No message\n");
			return 0;
		}

		GetMessage(&msg, NULL, 0, 0);
		if (msg.message == WM_KEYDOWN) {
			char buf[100];
			wsprintfA(buf, "%d\n", (int)msg.wParam);
			OutputDebugStringA(buf);
			return msg.wParam;
		}
		if (msg.message == WM_QUIT) {
			return -1;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

void Console::setCursor(int x, int y)
{
	HANDLE rHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { (short)x, (short)y };
	SetConsoleCursorPosition(rHnd, coord);
}

void Console::putChar(char ch)
{
	std::cout << ch;
}

void Console::sleep(int msec)
{
	Sleep(msec);
}
