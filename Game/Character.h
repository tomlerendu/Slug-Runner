#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include "GameObject.h"
#include "GameManager.h"

class Character
{
	float x;
	float y;
	float z;
	float xVelocity;
	float yVelocity;
	float zVelocity;
public:
	Character();
	void render(GameManager *gameManager);
};

#endif