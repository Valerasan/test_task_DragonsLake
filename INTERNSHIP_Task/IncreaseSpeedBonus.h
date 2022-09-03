#include "Bonus.h"


class IncreaseSpeedBonus : public Bonus
{
public:

	IncreaseSpeedBonus(int x, int y);
	~IncreaseSpeedBonus();

	virtual void UseAbility(Platform& platform) override;
};