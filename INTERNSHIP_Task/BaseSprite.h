#pragma once

#include "Framework.h"
#include <cmath>
#include "Global.h"

 
struct Rect
{
public:
	Rect()
	{
		x = 0;
		y = 0;
		right = 0;
		bottom = 0;
		width = 0;
		hight = 0;
	}

	int CentrX()
	{
		return x + width / 2;
	}
	int CentrY()
	{
		return y + hight / 2;
	}
	int x;
	int y;
	int right;
	int bottom;
	int width;
	int hight;
};

// Base class
class BaseSprite
{

private:
	Sprite* m_Sprite;

public:
	Rect SpriteRect;


	BaseSprite(const char* path);
	BaseSprite();

	~BaseSprite();

	void SetTexture(const char* path);
	void SetSize(int width, int hight);
	void SetPosition(int x, int y);

	void Draw();

	void MoveSprite(int x, int y);

	bool IsOverlap(BaseSprite* overlapSprite, bool& right);
	bool IsOverlap(BaseSprite* overlapSprite);

	// the direction of flight is calculated using the normalized vector
	void normalDirection(int Ax, int Ay, int Bx, int By, float& Result_X, float& Result_Y)
	{
		int dir_x = Ax - Bx;
		int dir_y = Ay - By;
		float length = sqrt(pow(dir_x, 2) + pow(dir_y, 2));
		float invLength = 1 / length;

		Result_X = invLength * dir_x;
		Result_Y = invLength * dir_y;
	}

	//static float dotProduct(float oneX, float oneY, float twoX, float twoY)
	//{
	//	return oneX * twoX + oneY * twoY;
	//}

	//static float VectorLength(float oneX, float oneY, float twoX, float twoY)
	//{
	//	return sqrt(pow((twoX - oneX) , 2) + pow((twoY - oneY), 2));
	//}

	// improved collision but unfortunately does not work
	//static Direction VectorDirection(Rect& one, Rect& two)
	//{
	//	float Result_X;
	//	float Result_Y;
	//	int minX = 0, minY = 0;
	//	float minLentgh = VectorLength(one.CentrX(), one.CentrY(), two.x, two.y);
	//	//for (int  i = 0; i < 3; i++)
	//	//{
	//	//	for (int j = 0; j < 3; j++)
	//	//	{
	//	//		float tmp = VectorLength(one.CentrX(), one.CentrY(), two.x + two.CentrX() * j, two.y + two.CentrY() * i);
	//	//		if (tmp < minLentgh)
	//	//		{
	//	//			minLentgh = tmp;
	//	//			//std::cout << minLentgh << std::endl;
	//	//			minX = two.x + two.CentrX() * j;
	//	//			minY = two.y + two.CentrY() * i;
	//	//		}
	//	//			
	//	//	}
	//	//}
	//	//std::cout << "--------------------------------------" <<  std::endl;
	//	for (int i = 0; i < 3; i++)
	//	{
	//		float tmp = VectorLength(one.CentrX(), one.CentrY(), two.x + two.CentrX() * i, two.CentrY());
	//		if (tmp < minLentgh)
	//		{
	//			minLentgh = tmp;
	//			//std::cout << minLentgh << std::endl;
	//			minX = two.x + two.CentrX() * i;
	//			minY = two.CentrY();
	//			//std::cout << minX << " " << minY << std::endl;
	//		}
	//	}
	//	//std::cout << "--------------------------------------" << std::endl;
	//	normalDirection(one.CentrX(), one.CentrY(),
	//		minX, minY,
	//		Result_X, Result_Y);
	//	//std::cout << Result_X << " " << Result_Y << std::endl;
	//	//if (Result_X > 0.5 && Result_X < 1.0 && Result_Y > -0.5 && Result_Y < 0.5)
	//	//{
	//	//	return Direction::RIGHT;
	//	//	
	//	//}
	//	//if (Result_X > -0.5 && Result_X < 0.5 && Result_Y > 0.5 && Result_Y < 1.0)
	//	//{
	//	//	return Direction::DOWN;
	//	//	
	//	//}
	//	//	
	//	//if (Result_X < -0.5 && Result_X > -1.0 && Result_Y > -0.5 && Result_Y < 0.5)
	//	//{
	//	//	return Direction::LEFT;
	//	//	
	//	//}
	//	//	
	//	//if (Result_X > -0.5 && Result_X < 0.5 && Result_Y < -0.5 && Result_Y > -1.0)
	//	//{
	//	//	return Direction::UP;
	//	//	
	//	//}
	//		
	//	float compass[4][2] = { {0.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, -1.0f}, {-1.0f, 0.0f} };
	//	float max = 0.0f;
	//	unsigned int best_match = -1;
	//	for (unsigned int i = 0; i < 4; i++)
	//	{
	//		float dot_product = dotProduct(Result_X, Result_Y, compass[i][0], compass[i][1]);
	//		if (dot_product > max)
	//		{
	//			max = dot_product;
	//			best_match = i;
	//		}
	//	}
	//	return (Direction)best_match;
	//	//return Direction::RIGHT;
	//}

protected:
	int WIDTH;
	int HIGHT;

};




