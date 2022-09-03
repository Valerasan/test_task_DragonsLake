#include "DecreaseSpeedBonus.h"


DecreaseSpeedBonus::DecreaseSpeedBonus(int x, int y) : Bonus(x, y, "data/41-Breakout-Tiles.png")
{
}

DecreaseSpeedBonus::~DecreaseSpeedBonus()
{
}

void DecreaseSpeedBonus::UseAbility(Platform& platform)
{
	platform.SetTickTime(getTickCount());
	platform.DecreaseSpeed();
}