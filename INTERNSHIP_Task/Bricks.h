#pragma once

#include "Framework.h"
#include "BaseSprite.h"
#include "Bonus.h"
#include "IncreaseSpeedBonus.h"
#include "DecreaseSpeedBonus.h"
#include <vector>

class Bricks : public BaseSprite
{
protected:
	bool bIsDead;
	
public:
	Bricks();
	~Bricks();

	virtual void Start();


	virtual void loseHP() = 0;
	virtual bool isDead() = 0;

	void SpawnBonus(std::vector<Bonus*>& bonuses);


};

