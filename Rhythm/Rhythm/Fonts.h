#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Fonts
{
public:
	static Fonts fonts;
	Font def;

	Fonts();
	~Fonts();
};


