#include "Bricks.h"

Bricks::Bricks()
{
}

Bricks::~Bricks()
{
}

void Bricks::Start()
{
	bIsDead = false;
}

void Bricks::SpawnBonus(std::vector<Bonus*>& bonuses)
{
	bonuses.emplace_back(new DecreaseSpeedBonus(SpriteRect.CentrX(), SpriteRect.CentrY()));
}
