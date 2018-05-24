#include <iostream>
#include "Console.h"

using namespace std;

int main(void)
{
	Console::clear();
	Console::setCursor(20, 5);
	cout << "Hello";

	return 0;
}