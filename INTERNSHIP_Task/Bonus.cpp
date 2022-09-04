#include "Bonus.h"


Bonus::Bonus(int x, int y, const char* path) : BaseSprite(path)
{
	SetSize(WIDTH * 0.09375f, HIGHT * 0.025f);
	SetPosition(x, y);
	dead = false;
}

Bonus::~Bonus()
{
}

void Bonus::Update(std::vector<Bonus*>& bonuses)
{
	Move();
	OutOfBounds(bonuses);
}

void Bonus::Move()
{
	MoveSprite(0, 1);
}


void Bonus::OutOfBounds(std::vector<Bonus*>& bonuses)
{
	if (SpriteRect.y > HIGHT)
	{
		dead = true;
		KillBonus(bonuses);
	}
		
}

//destroys the object marked dead
void Bonus::KillBonus(std::vector<Bonus*>& bonuses)
{
	bonuses.erase(remove_if(bonuses.begin(), bonuses.end(), [](const Bonus* i_bonus)
		{ return 1 == i_bonus->dead; }), bonuses.end());
}

void Bonus::UseAbility(Platform& platform)
{
	dead = true;
}
