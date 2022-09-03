#include "Platfrom.h"



Platform::Platform() :BaseSprite("data/50-Breakout-Tiles.png")

{
}

Platform::~Platform()
{
}

void Platform::Start()
{
	SetSize(150, 40);
	SetPosition(200, 750);
	speed = normalSpeed;
	Time = getTickCount();
}

void Platform::IncreaseSpeed()
{
	speed += normalSpeed * 0.4;	
	if(speed >= normalSpeed * 2)
		speed = normalSpeed * 2;
}

void Platform::DecreaseSpeed()
{
	speed -= normalSpeed * 0.4;
	if (speed <= normalSpeed / 2)
		speed = normalSpeed / 2;
}

void Platform::SetNormalSpeed()
{
	speed = normalSpeed;
}

void Platform::Update(PMove& move)
{
	Move(move);
	Borders();
	if ((getTickCount() - Time) / 1000 >= 20)
	{
		//std::cout << "20 seconds" << std::endl;
		SetNormalSpeed();
		Time = getTickCount();
	}
}

void Platform::Move(PMove& move)
{

	if (move.rigth)
		MoveSprite(speed, 0);
	else if (move.right)
		MoveSprite(-speed, 0);
}

void Platform::Borders()
{
	if (SpriteRect.x < 0)
		SetPosition(0, SpriteRect.y);
	else if (SpriteRect.right > 800)
		SetPosition(800 - SpriteRect.width, SpriteRect.y);
}

void Platform::SetTickTime(int Time)
{
	this->Time = Time;
	//std::cout << "Time set\n";
}