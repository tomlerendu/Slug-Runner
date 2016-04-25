#include "character.h"
#include <iostream>
#include <gl/glut.h>

Character::Character()
{
	x = 0;
	y = 0;
	z = 0;
	xVelocity = 0;
	yVelocity = 0;
	zVelocity = 0;
}

void Character::render(GameManager *gameManager)
{
	glPushMatrix();
	glPopMatrix();
}