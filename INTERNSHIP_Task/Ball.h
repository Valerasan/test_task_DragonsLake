#include "Framework.h"
#include "BaseSprite.h"
#include "Platfrom.h"

class Ball : public BaseSprite
{
private:
	// if calm the ball will follow the platform
	bool bIsCalm; 
	bool bIsOutOfBounds;
	// pointer platform followed by
	Platform* platform;

public:
	//ball flight direction
	float move_x;
	float move_y;

	Ball(Platform* platform);
	~Ball(); 

	void Start();

	void Update();
	void Move();

	void Start(int x, int y);
	void Borders();

	bool IsOutOfBounds() { return bIsOutOfBounds; };

};