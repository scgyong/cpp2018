#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "Circle.h"

int main(void)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {
		int x = rand() % 1000 + 50;
		int y = rand() % 1000 + 50;
		int r = rand() % 50 + 20;
		Circle c(x, y, r, "");
		//c.x = 20;
		//c.x = -20;
		c.setCenter(20, y);
		c.draw();
	}
	//Circle c1(100, 100, 50, "red"), c2(100, 200, 40, "yellow");
	////c1.x = 100;
	////c1.y = 100;
	////c1.radius = 40;
	//c1.draw();
	////c2.x = 100;
	////c2.y = 200;
	////c2.radius = 40;
	//c2.draw();

	//for (int i = 0; i < 20; i++) {
	//	Sleep(500);
	//	c1.move();
	//	c1.draw();
	//	c2.move();
	//	c2.draw();
	//}

	return 0;
}
