#include "BaseSprite.h"
#include <iostream>

BaseSprite::BaseSprite(const char* path)
{
	SetTexture(path);
	
}

BaseSprite::BaseSprite()
{
}

//BaseSprite::BaseSprite(int x, int y,
//	int width, int hight,
//	const char* path)
//{
//	SetTexture(path);
//	SpriteRect = Rect(x, y, width, hight);
//}

BaseSprite::~BaseSprite()
{
	delete m_Sprite;
}

void BaseSprite::SetTexture(const char* path)
{
	m_Sprite = createSprite(path);
}

void BaseSprite::SetSize(int width, int hight)
{
	SpriteRect.right = SpriteRect.x + width;
	SpriteRect.bottom = SpriteRect.y + hight;
	SpriteRect.width = width;
	SpriteRect.hight = hight;
	setSpriteSize(m_Sprite, width, hight);

}

void BaseSprite::SetPosition(int x, int y)
{
	SpriteRect.x = x;
	SpriteRect.y = y;
	SpriteRect.right = x + SpriteRect.width;
	SpriteRect.bottom = y + SpriteRect.hight;

}

//void BaseSprite::UpdateSpr()
//{
//
//}

void BaseSprite::Draw()
{
	drawSprite(m_Sprite, SpriteRect.x, SpriteRect.y);
}

void BaseSprite::MoveSprite(int x, int y)
{
	SpriteRect.x += x;
	SpriteRect.y += y;
	SpriteRect.right += x;
	SpriteRect.bottom += y;
}

bool BaseSprite::IsOverlap(BaseSprite* overlapSprite, bool& reght)
{


	if (SpriteRect.right >= overlapSprite->SpriteRect.x &&
		overlapSprite->SpriteRect.right >= SpriteRect.x &&
		SpriteRect.bottom >= overlapSprite->SpriteRect.y &&
		overlapSprite->SpriteRect.bottom >= SpriteRect.y)
	{
		//std::cout << "Yes\n";
		if (SpriteRect.x == overlapSprite->SpriteRect.right)
		{
			//std::cout << "Right\n";
			reght = true;
		}	
		else if (SpriteRect.right == overlapSprite->SpriteRect.x )
		{
			//std::cout << "Left\n";
			reght = true;
		}
			
		return true;
	}


		
	return false;
}

bool BaseSprite::IsOverlap(BaseSprite* overlapSprite)
{
	if (SpriteRect.right >= overlapSprite->SpriteRect.x &&
		overlapSprite->SpriteRect.right >= SpriteRect.x &&
		SpriteRect.bottom >= overlapSprite->SpriteRect.y &&
		overlapSprite->SpriteRect.bottom >= SpriteRect.y)
	{
		return true;
	}

	return false;
}