#include "GreenBrick.h"
#include <iostream>

GreenBrick::GreenBrick()
{
	Start();
}

GreenBrick::~GreenBrick()
{
}

void GreenBrick::Start()
{
	Bricks::Start();
	HP = maxHP;
	SetTexture("data/15-Breakout-Tiles.png");
	SetSize(80, 20);
}

void GreenBrick::loseHP()
{
	--HP;
	if (HP < maxHP)
	{
		SetTexture("data/16-Breakout-Tiles.png");
		SetSize(80, 20);
	}

	bIsDead = HP <= 0 ? true : false;
	//std::cout << bIsDead ? "Dead\n" : "No\n";
}

bool GreenBrick::isDead()
{
	return bIsDead;
}
