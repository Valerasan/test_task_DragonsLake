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
	HP = maxHP;
	SetTexture("data/15-Breakout-Tiles.png");
	Bricks::Start();
}

void GreenBrick::loseHP()
{
	--HP;
	if (HP < maxHP)
	{
		SetTexture("data/16-Breakout-Tiles.png");
		SetSize(SpriteRect.width, SpriteRect.hight);
	}

	bIsDead = HP <= 0 ? true : false;
}

bool GreenBrick::isDead()
{
	return bIsDead;
}
