#include "GoldBrick.h"

GoldBrick::GoldBrick()
{
	Start();
}

GoldBrick::~GoldBrick()
{
}

void GoldBrick::Start()
{
	Bricks::Start();
	SetTexture("data/13-Breakout-Tiles.png");
	SetSize(80, 20);
	
}

void GoldBrick::loseHP()
{
}

bool GoldBrick::isDead()
{
	return bIsDead;
}
