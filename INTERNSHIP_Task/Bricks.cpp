#include "Bricks.h"

Bricks::Bricks()
{
	srand(time(NULL));
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
	if (rand() % 100 <= 25)
	{
		if(rand() % 2 == 1)
		{
			bonuses.emplace_back(new DecreaseSpeedBonus(SpriteRect.CentrX(), SpriteRect.CentrY()));
		}
		else
		{
			bonuses.emplace_back(new IncreaseSpeedBonus(SpriteRect.CentrX(), SpriteRect.CentrY()));
		}
	}
	
}
