#pragma once
#include "Bricks.h"
class GoldBrick : public Bricks
{
public:
	GoldBrick();
	~GoldBrick();

	virtual void Start() override;
	virtual void loseHP() override;
	virtual bool isDead() override;
};

