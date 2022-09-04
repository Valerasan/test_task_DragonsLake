#include "Ball.h"
#include <cmath>

Ball::Ball(Platform* platform) : BaseSprite("data/64-Breakout-Tiles.png")
{

	this->platform = platform;
	Start();
}

Ball::~Ball()
{
	delete platform;
}

void Ball::Start()
{
	SetSize(WIDTH * 0.02f, HIGHT * 0.02f);
	SetPosition(platform->SpriteRect.x + platform->SpriteRect.width / 2, platform->SpriteRect.y - 16);
	bIsCalm = true;
	bIsOutOfBounds = false;
}

void Ball::Update()
{
	Move();
	Borders();
}

void Ball::Move()
{
	if (bIsCalm)
		SetPosition(platform->SpriteRect.x + platform->SpriteRect.width / 2, platform->SpriteRect.y - SpriteRect.hight);
	else
		MoveSprite(move_x * 3, move_y * 3 );
}

void Ball::Start(int x, int y)
{
	bIsCalm = false;

	normalDirection(x, y, SpriteRect.CentrX(), SpriteRect.CentrY(), move_x, move_y);
}

void Ball::Borders()
{
	if (SpriteRect.x < 0)
		move_x *= -1;
	else if (SpriteRect.right > WIDTH)
		move_x *= -1;

	if (SpriteRect.y < 0)
		move_y *= -1;
	else if (SpriteRect.bottom > HIGHT)
		bIsOutOfBounds = true;
}