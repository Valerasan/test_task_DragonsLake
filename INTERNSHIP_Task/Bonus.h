#pragma once
#include "BaseSprite.h"
#include "Platfrom.h"

class Bonus : public BaseSprite
{

public:
	bool dead;

	Bonus(int x, int y, const char* path);
	~Bonus();


	void Update();
	void Move();
	virtual void UseAbility(Platform& platform) = 0;

};

