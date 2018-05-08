#include <vector>
#include <iostream>

#include "Sprite.h"
#include "Hero.h"
#include "Board.h"
#include "Treasure.h"
#include "Enemy.h"
#include "Console.h"

using namespace std;

int main(void)
{
	Console::clear();

	Board board;

	vector<Sprite *> list;
	list.push_back(new Hero(0, 0));
	list.push_back(new Treasure(20, 10));
	list.push_back(new Enemy(3, 3));

	while (true) {
		Console::setCursor(0, 0);
		board.clear();
		for (auto &e : list) {
			board.set(*e);
		}
		board.print();

		int key = Console::getch();
		if (key == 'q') {
			break;
		}

		for (auto &e : list) {
			try {
				e->move(key);
			} catch (int) {
				//
			}
		}
	}

	for (auto &e : list) {
		delete e;
	}

	return 0;
}
