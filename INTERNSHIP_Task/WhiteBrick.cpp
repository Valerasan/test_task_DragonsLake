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
	Bricks::Start();
	HP = maxHP;
	SetTexture("data/01-Breakout-Tiles.png");
	SetSize(80, 20);
}

void WhiteBrick::loseHP()
{
	--HP;
	bIsDead = HP <= 0 ? true : false;
	//std::cout << bIsDead ;
}

bool WhiteBrick::isDead()
{
	return bIsDead;
}
