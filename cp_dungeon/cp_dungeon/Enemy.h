#pragma once
#include "Sprite.h"
class Enemy :
	public Sprite
{
public:
	Enemy(int x, int y);
	virtual ~Enemy();
};

