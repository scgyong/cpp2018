#include <vector>

#include "Sprite.h"
#include "Hero.h"
#include "Board.h"
#include "Treasure.h"
#include "Enemy.h"

using namespace std;

int main(void)
{
	Board board;

	vector<Sprite *> list;
	list.push_back(new Hero(0, 0));
	list.push_back(new Treasure(20, 10));
	list.push_back(new Enemy(3, 3));

	board.clear();
	for (auto &e : list) {
		board.set(*e);
	}
	board.print();

	for (auto &e : list) {
		delete e;
	}

	return 0;
}
