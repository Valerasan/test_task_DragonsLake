#include "Ball.h"
#include <cmath>

Ball::Ball(Platform* platform) : BaseSprite("data/64-Breakout-Tiles.png")
{
	SetSize(16, 16);
	//SetPosition(platform->SpriteRect.x + platform->SpriteRect.width/2, platform->SpriteRect.y -16);

	this->platform = platform;
	calm = true;

}

Ball::~Ball()
{
	delete platform;
}

void Ball::Start()
{
	SetPosition(platform->SpriteRect.x + platform->SpriteRect.width / 2, platform->SpriteRect.y - 16);
	calm = true;
}

void Ball::Update()
{
	Move();
	Borders();
}

void Ball::Move()
{
	if (calm)
		SetPosition(platform->SpriteRect.x + platform->SpriteRect.width / 2, platform->SpriteRect.y - SpriteRect.hight);
	else
	{
		MoveSprite(move_x * 3, move_y * 3 );
		//std::cout << move_x;
	}
		
}

void Ball::Start(int x, int y)
{
	calm = false;

	normalDirection(x, y, SpriteRect.CentrX(), SpriteRect.CentrY(), move_x, move_y);

	//int dir_x = x - (SpriteRect.x + SpriteRect.width / 2);
	//int dir_y = y - (SpriteRect.y + SpriteRect.hight / 2);
	////std::cout <<"Start " << SpriteRect.x + SpriteRect.width / 2 << " " << SpriteRect.y + SpriteRect.hight / 2 << std::endl;
	////std::cout << "End " << x << " " << y << std::endl;
	////std::cout << "Direct " << dir_x << " " << dir_y << std::endl;
	//float length = sqrt(pow(dir_x, 2) + pow(dir_y, 2));
	////std::cout << length << " " << y << std::endl;

	//float invLength = 1 / length;
	////std::cout << invLength << " " << y << std::endl;

	//move_x = invLength * dir_x;
	//move_y = invLength * dir_y;


	//std::cout << move_x << " " << move_y << std::endl;
	
}

void Ball::Borders()
{
	if (SpriteRect.x < 0)
		move_x *= -1;
	else if (SpriteRect.right > 800)
		move_x *= -1;

	if (SpriteRect.y < 0)
		move_y *= -1;
	else if (SpriteRect.bottom > 800)
		move_y *= -1;
}