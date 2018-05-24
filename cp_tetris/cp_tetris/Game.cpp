#include "Game.h"
#include "Board.h"
#include "Block.h"
#include "Console.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::start()
{
	Console::clear();
	Board board;
	Block block;
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
			break;
		case 'l':
			block.move(1);
			break;
		case 'k':
			block.moveDown();
			break;
		}
		Console::clear();
		block.draw();
	}
}
