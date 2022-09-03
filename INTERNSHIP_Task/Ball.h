#include "Framework.h"
#include "BaseSprite.h"
#include "Platfrom.h"

class Ball : public BaseSprite
{
private:
	bool calm;
	Platform* platform;



public:

	float move_x;
	float move_y;

	Ball(Platform* platform);
	~Ball(); 

	void Start();

	void Update();
	void Move();

	void Start(int x, int y);
	void Borders();

};