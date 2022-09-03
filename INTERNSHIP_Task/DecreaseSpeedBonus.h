#include "Bonus.h"


class DecreaseSpeedBonus : public Bonus
{
public:

	DecreaseSpeedBonus(int x, int y);
	~DecreaseSpeedBonus();

	virtual void UseAbility(Platform& platform) override;
};