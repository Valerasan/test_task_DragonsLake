#include "Framework.h";
#include "Platfrom.h"
#include "Ball.h"
#include "Bricks.h"
#include "GoldBrick.h"
#include "GreenBrick.h"
#include "WhiteBrick.h";
#include "Bonus.h"
#include <vector>

class Game : public Framework {

private:


	const int N_OF_BLOCKS = 24;

	Platform * platform;
	Ball* ball;
	Bricks* bricks[24];
	BaseSprite* background;
	std::vector<Bonus*> bonuses;

	
	PMove move;
	int x_start;
	int y_start;

	int score;
	int combo;

	bool right = false;
	bool IsGameOver;
	bool gameStart;

	int deadBlocks = 0;

public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = WIDTH;
		height = HIGHT;
		fullscreen = false;
	}

	virtual bool Init() {
		
		platform = new Platform();
		ball = new Ball(platform);
		background = new BaseSprite("data/Background.jpg");
		
		int W, H;
		getScreenSize(W, H);
		background->SetSize(W, H);
		for (int i = 0; i < 8; i++)
		{
			bricks[i] = new GreenBrick();
			bricks[i]->SetPosition((W * 0.1) + (W * 0.1) * i, (H * 0.1875));
		}
		for (int i = 0; i < 8; i++)
		{
			bricks[8 + i] = new WhiteBrick();
			bricks[8 + i]->SetPosition((W * 0.1) + (W * 0.1) * i, (H* 0.2125));
		}
		for (int i = 0; i < 8; i++)
		{
			bricks[16 + i] = new GoldBrick();
			bricks[16 + i]->SetPosition((W * 0.1) + (W * 0.1) * i, (H * 0.2375));
		}
		
		 ClearAll();
		return true;
	}

	virtual void Close() 
	{
		delete platform;
		delete ball;
		delete[] bricks;
		delete background;
	}

	virtual bool Tick() 
	{
		Update();
		
		if(ball->IsOutOfBounds())
			IsGameOver = true;

		if (IsGameOver)
		{
			ClearAll();
		}
		
		// ball - platform contact
		if (ball->IsOverlap(platform))
		{
			ball->move_y *= -1;
			combo = 0;
		}

		//bonuses - platform contact
		for (Bonus* bonus : bonuses)
		{
			if (bonus->IsOverlap(platform))
			{
				bonus->UseAbility(*platform);
				bonus->KillBonus(bonuses);
			}
		}
			
		//ball - bricks contact
		for (Bricks* brick : bricks)
		{
			if (ball->IsOverlap(brick, right))
			{
				
				if (brick->isDead())
				{
					break;
				}
				
				if (right)
				{
					right = false;
					ball->move_x *= -1;
				}
				else
				{
					ball->move_y *= -1;
				}
				
				brick->loseHP();
				if (brick->isDead())
				{
					combo++;
					deadBlocks++;
					brick->SpawnBonus(bonuses);
					if (combo > 3)
					{
						score += 60;
						std::cout << "Score: " << score << std::endl;
					}	
					else
					{
						score += 20;
						std::cout << "Score: " << score << std::endl;
					}

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
			if (!gameStart)
			{
				ball->Start(x_start, y_start);
				gameStart = true;
			}
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
		gameStart = false;
		score = 0;
		combo = 0;

		system("CLS");
		platform->Start();
		ball->Start();
		for (int i = 0; i < 24; i++)
			bricks[i]->Start();

		for (Bonus* bonus : bonuses)
		{
			bonus->dead = true;
			bonus->KillBonus(bonuses);
		}
	}

	void Update()
	{
		platform->Update(move);
		ball->Update();
		for (Bonus* bonus : bonuses)
		{
			bonus->Update(bonuses);
		}
	}

	void Render()
	{
		drawTestBackground();
		background->Draw();
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
	std::vector<int> resolution;
	bool found = false;
	int number = 0;
	if (!strcmp(argv[1], "-window"))
	{
		for (int i = 0; i < strlen(argv[2]); i++) {
			const char ch = argv[2][i];
			if (ch >= '0' && ch <= '9') {
				const int digit = ch - '0';
				number = number * 10 + digit;
				found = true;
			}
			else {
				if (found) {
					resolution.push_back(number);

					number = 0;
					found = false;
				}
			}
		}
		if (found) {
			resolution.push_back(number);
		}
	}
	else
	{
		WIDTH = 800;
		HIGHT = 800;
	}
	WIDTH = resolution[0];
	HIGHT = resolution[1];

	return run(new Game);
}
