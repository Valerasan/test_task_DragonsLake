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
	SetTexture("data/13-Breakout-Tiles.png");
	Bricks::Start();
}

void GoldBrick::loseHP()
{
}

bool GoldBrick::isDead()
{
	return bIsDead;
}
