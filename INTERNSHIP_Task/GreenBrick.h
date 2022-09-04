#pragma once
#include "Bricks.h"

class GreenBrick : public Bricks
{

private:

	int HP;
	const int maxHP = 2;

public:
	GreenBrick();
	~GreenBrick();

	virtual void Start() override;
	virtual void loseHP() override;
	virtual bool isDead() override;

};

