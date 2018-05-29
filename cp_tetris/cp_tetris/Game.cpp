#include <stdlib.h>
#include <time.h>

#include "Game.h"
#include "Board.h"
#include "Block.h"
#include "Console.h"

Game::Game()
{
	srand((unsigned)time(NULL));
}


Game::~Game()
{
}
#include <windows.h>

void Game::start()
{
	Board board;
	Block block;
	block.init();

	Console::clear();
	block.draw();

	int prev_time = Console::getSystemTime();
	bool loop = true;
	while (loop) {
		//Console::sleep(100);
		bool redraws = false;
		int now = Console::getSystemTime();
		int ch = Console::getch();

		char buf[100];
		wsprintfA(buf, "%d : %d - %d = %d\n", ch, prev_time, now, (now - prev_time));
		OutputDebugStringA(buf);

		switch (ch) {
		case 'q':
			loop = false;
			continue;
		case 'j':
			if (block.move(-1)) {
				redraws = true;
			}
			break;
		case 'l':
			if (block.move(1)) {
				redraws = true;
			}
			break;
		case 'k':
			if (block.moveDown()) {
				redraws = true;
				prev_time = now;
			}
			break;
		case 'i':
			if (block.rotate()) {
				redraws = true;
			}
			break;
		}
		if (now - prev_time > 1000) {
			prev_time += 1000;
			if (!block.moveDown()) {
				board.plant(block);
				board.deleteLines();
				block.init();
			}
			redraws = true;
		}
		if (redraws) {
			Console::clear();
			board.draw();
			block.draw();
			redraws = false;
		}
	}
}
