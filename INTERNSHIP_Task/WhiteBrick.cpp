#include "WhiteBrick.h"
#include <iostream>

WhiteBrick::WhiteBrick()
{
	Start();
}

WhiteBrick::~WhiteBrick()
{
}

void WhiteBrick::Start()
{
	HP = maxHP;
	SetTexture("data/01-Breakout-Tiles.png");
	Bricks::Start();
}

void WhiteBrick::loseHP()
{
	--HP;
	bIsDead = HP <= 0 ? true : false;
}

bool WhiteBrick::isDead()
{
	return bIsDead;
}
