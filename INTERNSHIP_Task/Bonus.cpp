#include "Bonus.h"
#include "Bonus.h"

Bonus::Bonus(int x, int y, const char* path) : BaseSprite(path)
{
	SetSize(75, 20);
	SetPosition(x, y);
	dead = false;
}

Bonus::~Bonus()
{
	
}

void Bonus::Update()
{
	Move();
}

void Bonus::Move()
{
	MoveSprite(0, 1);
}

void Bonus::UseAbility(Platform& platform)
{
	dead = true;
}
