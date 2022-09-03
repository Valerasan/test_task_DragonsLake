#pragma once
#include "Bricks.h"

class WhiteBrick : public Bricks
{
private:

	int HP;
	const int maxHP = 1;

public:
	WhiteBrick();
	~WhiteBrick();

	virtual void Start() override;
	virtual void loseHP() override;
	virtual bool isDead() override;

};

