#include "MovingBlock.h"
#include <iostream>
#include <gl/glut.h>

MovingBlock::MovingBlock()
{
	setDirection(MoveDirection::MOVE_Z);
}

void MovingBlock::setDirection(MoveDirection direction)
{
	this->direction = direction;
	this->blockSize = (direction == MOVE_Z) ? getXSize() : getZSize();
}

void MovingBlock::setSpeed(int speed)
{
	this->speed = (100 - speed) * 10;
}

void MovingBlock::update(GameManager *gameManager)
{
	//Figure out the new position for the block
	int ticks = gameManager->getTick();
	float distance = (direction == MOVE_Z) ? getZSize() : getXSize();
	
	//Find out the total distance the block must move in one cycle
	float movingDistance = distance * 2 - blockSize * 2;

	//Find out where the block should be now
	float covered = ((float)(ticks % ((int)movingDistance * speed)) / speed);

	if (covered > distance - blockSize)
		covered = (distance - blockSize) - (covered - distance) - blockSize;

	covered -= (distance/2) - (blockSize/2);

	//Update the block position
	if (direction == MOVE_Z)
		blockZ = covered;
	else
		blockX = covered;
}

void MovingBlock::render(GameManager *gameManager)
{
	glPushMatrix();
		
		glTranslatef(getXPos(), getYPos(), getZPos());
		if (direction == MOVE_Z)
			glTranslatef(0, 0, blockZ);
		else
			glTranslatef(blockX, 0, 0);
		
		glBindTexture(GL_TEXTURE_2D, gameManager->getTextureManager().getTexture("blockTop"));
		glBegin(GL_QUADS);
			//Top
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(blockSize / 2, getYSize() / 2, blockSize / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-blockSize / 2, getYSize() / 2, blockSize / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-blockSize / 2, getYSize() / 2, -blockSize / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(blockSize / 2, getYSize() / 2, -blockSize / 2);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, gameManager->getTextureManager().getTexture("blockSide"));
		glBegin(GL_QUADS);
			//Front
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(blockSize / 2, getYSize() / 2, blockSize / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-blockSize / 2, getYSize() / 2, blockSize / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-blockSize / 2, -getYSize() / 2, blockSize / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(blockSize / 2, -getYSize() / 2, blockSize / 2);
			//Left
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-blockSize / 2, getYSize() / 2, blockSize / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-blockSize / 2, -getYSize() / 2, blockSize / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-blockSize / 2, -getYSize() / 2, -blockSize / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-blockSize / 2, getYSize() / 2, -blockSize / 2);
			//Back
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(blockSize / 2, getYSize() / 2, -blockSize / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-blockSize / 2, getYSize() / 2, -blockSize / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-blockSize / 2, -getYSize() / 2, -blockSize / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(blockSize / 2, -getYSize() / 2, -blockSize / 2);
			//Right
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(blockSize / 2, getYSize() / 2, blockSize / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(blockSize / 2, -getYSize() / 2, blockSize / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(blockSize / 2, -getYSize() / 2, -blockSize / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(blockSize / 2, getYSize() / 2, -blockSize / 2);
			//Bottom
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(blockSize / 2, -getYSize() / 2, blockSize / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-blockSize / 2, -getYSize() / 2, blockSize / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-blockSize / 2, -getYSize() / 2, -blockSize / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(blockSize / 2, -getYSize() / 2, -blockSize / 2);
		glEnd();

	glPopMatrix();
}