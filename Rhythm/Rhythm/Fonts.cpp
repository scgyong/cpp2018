#include "Fonts.h"


Fonts Fonts::fonts;

Fonts::Fonts()
{
	bool ret = def.loadFromFile("kbiz.ttf");
	printf("loadFromFile returns: %d\n", ret);
}


Fonts::~Fonts()
{
}
