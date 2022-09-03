#pragma once

#include "Framework.h"
#include "BaseSprite.h"
#include <iostream>

struct PMove
{
	bool rigth = false;
	bool right = false;
};


class Platform: public BaseSprite
{
private:
	int speed;
	const int normalSpeed = 5;
	int Time;

public:


	Platform();

	~Platform();

	void Start();

	//void Draw() override;
	void IncreaseSpeed();
	void DecreaseSpeed();
	void SetNormalSpeed();
	void Update(PMove& move);
	void Move(PMove& move);
	void Borders();

	void SetTickTime(int Time);
};

