
#include "Framework.h";
#include "Platfrom.h"
#include "Ball.h"
#include "Bricks.h"
#include "GoldBrick.h"
#include "GreenBrick.h"
#include "WhiteBrick.h";
#include "Bonus.h"
#include <vector>




/* Test Framework realization */
class Game : public Framework {

private:


	const int N_OF_BLOCKS = 24;

	Platform * platform;
	Ball* ball;
	Bricks* bricks[24];
	std::vector<Bonus*> bonuses;

	
	PMove move;
	int x_start;
	int y_start;

	int score;
	int combo;

	bool right = false;
	bool IsGameOver = true;

	int deadBlocks = 0;

public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 800;
		height = 800;
		fullscreen = false;
	}

	virtual bool Init() {
		
		platform = new Platform();
		ball = new Ball(platform);
		for (int i = 0; i < 8; i++)
		{
			bricks[i] = new GoldBrick();
			bricks[i]->SetPosition(80 + 80 * i, 150);
		}
		for (int i = 0; i < 8; i++)
		{
			bricks[8 + i] = new GreenBrick();
			bricks[8 + i]->SetPosition(80 + 80 * i, 170);
		}
		for (int i = 0; i < 8; i++)
		{
			bricks[16 + i] = new WhiteBrick();
			bricks[16 + i]->SetPosition(80 + 80 * i, 190);
		}
		
		score = 0;
		combo = 0;
		return true;
	}

	virtual void Close() 
	{
		//delete platform;
		//delete ball;
		//delete[] bricks;
	}

	virtual bool Tick() 
	{
		Update();
		
		if (IsGameOver)
		{
			ClearAll();
		}
		
		
		if (ball->IsOverlap(platform))
		{
			//BaseSprite::VectorDirection(ball->SpriteRect, platform->SpriteRect);
			ball->move_y *= -1;
			combo = 0;
			//switch (BaseSprite::VectorDirection(ball->SpriteRect, platform->SpriteRect))
			//{
			//case Direction::DOWN:
			//	std::cout << "D\n";
			//	ball->move_y *= -1;
			//	break;
			//case Direction::UP:
			//	std::cout << "u\n";
			//	ball->move_y *= -1;
			//	break;
			//case Direction::RIGHT:
			//	std::cout << "Rigth\n";
			//case Direction::LEFT:
			//	std::cout << "R\n";
			//	ball->move_x *= -1;
			//	break;
			//default:
			//	break;
			//}
		}


		for (Bonus* bonus : bonuses)
		{
			if (bonus->IsOverlap(platform))
			{
				bonus->UseAbility(*platform);
				
				bonuses.erase(remove_if(bonuses.begin(), bonuses.end(), [](const Bonus* i_bonus)
					{ return 1 == i_bonus->dead; }), bonuses.end());
			}
		}
			
		for (Bricks* brick : bricks)
		{
			if (ball->IsOverlap(brick, right))
			{
				
				if (brick->isDead())
				{
					break;
				}
				
				//switch (BaseSprite::VectorDirection(ball->SpriteRect, brick->SpriteRect))
				//{
				//case Direction::DOWN:
				//	std::cout << "DOWN\n";
				//	ball->move_y *= -1;
				//	break;
				//case Direction::UP:
				//	std::cout << "UP\n";
				//	ball->move_y *= -1;
				//	break;
				//case Direction::RIGHT:
				//	std::cout << "Rigth\n";
				//	ball->move_x *= -1;
				//	break;
				//case Direction::LEFT:
				//	std::cout << "Left\n";
				//	ball->move_x *= -1;
				//	break;
				//default:
				//	break;
				//}
				if (right)
				{
					right = false;
					ball->move_x *= -1;
				}
				else
				{
					ball->move_y *= -1;
				}
				
			
				//if (combo > 3)
				//{
				//	score += 60;
				//}
				//else
				//{
				//	score += 20;
				//}
				//std::cout << "Score: " << score << std::endl;
				brick->loseHP();
				if (brick->isDead())
				{
					combo++;
					deadBlocks++;
					brick->SpawnBonus(bonuses);
					if (deadBlocks == 16)
					{
						IsGameOver = true;
						deadBlocks = 0;
					}
				}
				break;
			}
		}


		Render();
		

		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) 
	{
		this->x_start = x;
		this->y_start = y;
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) 
	{
		switch (button)
		{
		case FRMouseButton::right:
			ball->Start(x_start, y_start);
			break;
		case FRMouseButton::MIDDLE:
			break;
		case FRMouseButton::RIGHT:
			break;
		case FRMouseButton::COUNT:
			break;
		default:
			break;
		}
	}

	virtual void onKeyPressed(FRKey k) 
	{
		switch (k)
		{
		case FRKey::RIGHT:
			move.rigth = true;
			//std::cout << "Rigth\n";
			break;
		case FRKey::right:
			move.right = true;
			//std::cout << "right\n";
			break;
		case FRKey::DOWN:
			break;
		case FRKey::UP:
			break;
		case FRKey::COUNT:
			break;
		default:
			break;
		}
	}

	virtual void onKeyReleased(FRKey k) 
	{
		switch (k)
		{
		case FRKey::RIGHT:
			move.rigth = false;
			break;
		case FRKey::right:
			move.right = false;
			break;
		case FRKey::DOWN:
			break;
		case FRKey::UP:
			break;
		case FRKey::COUNT:
			break;
		default:
			break;
		}
	}

	virtual const char* GetTitle() override
	{
		return "Arcanoid";
	}

	void ClearAll()
	{
		IsGameOver = false;
		platform->Start();
		ball->Start();
		for (int i = 0; i < 24; i++)
			bricks[i]->Start();

		for (Bonus* bonus : bonuses)
		{
			bonus->dead = true;
		}
		bonuses.erase(remove_if(bonuses.begin(), bonuses.end(), [](const Bonus* i_bonus)
			{ return 1 == i_bonus->dead; }), bonuses.end());
		score = 0;
		combo = 0;
	}

	void Update()
	{
		platform->Update(move);
		ball->Update();
		for (Bonus* bonus : bonuses)
		{
			bonus->Update();
		}
	}

	void Render()
	{
		drawTestBackground();
		platform->Draw();
		ball->Draw();

		for (Bonus* bonus : bonuses)
		{
			bonus->Draw();
		}

		for (Bricks* brick : bricks)
		{
			if (!brick->isDead())
				brick->Draw();

		}
	}
};

int main(int argc, char* argv[])
{
	return run(new Game);
}
