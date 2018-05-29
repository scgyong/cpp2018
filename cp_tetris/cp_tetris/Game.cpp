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

void Game::start()
{
	Board board;
	Block block;
	block.init();

	Console::clear();
	block.draw();

	int tick_count = 0;
	bool loop = true;
	while (loop) {
		Console::sleep(100);
		int ch = Console::getch();
		switch (ch) {
		case 'q':
			loop = false;
			continue;
		case 'j':
			block.move(-1);
			tick_count = 0;
			break;
		case 'l':
			block.move(1);
			tick_count = 0;
			break;
		case 'k':
			block.moveDown();
			tick_count = 0;
			break;
		case 'i':
			block.rotate();
			tick_count = 0;
			break;
		}
		if (++tick_count > 2) {
			tick_count = 0;
			if (!block.moveDown()) {
				board.plant(block);
				board.deleteLines();
				block.init();
			}
		}
		Console::clear();
		board.draw();
		block.draw();
	}
}
