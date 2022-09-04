#include "Bricks.h"

Bricks::Bricks()
{
	srand(time(NULL));
}

Bricks::~Bricks()
{
}

//should be called at the end
void Bricks::Start()
{
	bIsDead = false;
	SetSize(WIDTH * 0.1, HIGHT * 0.025);
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
