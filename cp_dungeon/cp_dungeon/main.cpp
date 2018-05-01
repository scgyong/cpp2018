#include "Sprite.h"
#include "Hero.h"
#include "Board.h"

int main(void)
{
	Board board;
	//board.clear();
	board.set(10, 10, 'X');
	board.set(15, 7, 'Z');
	board.print();

	return 0;
}
