#include "IncreaseSpeedBonus.h"


IncreaseSpeedBonus::IncreaseSpeedBonus(int x, int y) : Bonus(x, y, "data/42-Breakout-Tiles.png")
{
}

IncreaseSpeedBonus::~IncreaseSpeedBonus()
{
}

void IncreaseSpeedBonus::UseAbility(Platform& platform)
{
	Bonus::UseAbility(platform);
	platform.SetTickTime(getTickCount());
	platform.IncreaseSpeed();
}