#pragma once
#include "BaseSprite.h"
#include "Platfrom.h"
#include <vector>

class Bonus : public BaseSprite
{

public:
	bool dead;

	Bonus(int x, int y, const char* path);
	~Bonus();


	void Update(std::vector<Bonus*>& bonuses);
	void Move();
	void OutOfBounds(std::vector<Bonus*>& bonuses);
	void KillBonus(std::vector<Bonus*>& bonuses);
	virtual void UseAbility(Platform& platform);
	

};

