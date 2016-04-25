#include "block.h"
#include <iostream>
#include <gl/glut.h>

void Block::render(GameManager *gameManager)
{
	glPushMatrix();

		glTranslatef(getXPos(), getYPos(), getZPos());

		glBindTexture(GL_TEXTURE_2D, gameManager->getTextureManager().getTexture("blockTop"));
		glBegin(GL_QUADS);
			//Top
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(getXSize() / 2, getYSize() / 2, getZSize() / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-getXSize() / 2, getYSize() / 2, getZSize() / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-getXSize() / 2, getYSize() / 2, -getZSize() / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(getXSize() / 2, getYSize() / 2, -getZSize() / 2);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, gameManager->getTextureManager().getTexture("blockSide"));
		glBegin(GL_QUADS);
			//Front
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(getXSize() / 2, getYSize() / 2, getZSize() / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-getXSize() / 2, getYSize() / 2, getZSize() / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-getXSize() / 2, -getYSize() / 2, getZSize() / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(getXSize() / 2, -getYSize() / 2, getZSize() / 2);
			//Left
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-getXSize() / 2, getYSize() / 2, getZSize() / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-getXSize() / 2, -getYSize() / 2, getZSize() / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-getXSize() / 2, -getYSize() / 2, -getZSize() / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-getXSize() / 2, getYSize() / 2, -getZSize() / 2);
			//Back
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(getXSize() / 2, getYSize() / 2, -getZSize() / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-getXSize() / 2, getYSize() / 2, -getZSize() / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-getXSize() / 2, -getYSize() / 2, -getZSize() / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(getXSize() / 2, -getYSize() / 2, -getZSize() / 2);
			//Right
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(getXSize() / 2, getYSize() / 2, getZSize() / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(getXSize() / 2, -getYSize() / 2, getZSize() / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(getXSize() / 2, -getYSize() / 2, -getZSize() / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(getXSize() / 2, getYSize() / 2, -getZSize() / 2);
			//Bottom
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(getXSize() / 2, -getYSize() / 2, getZSize() / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-getXSize() / 2, -getYSize() / 2, getZSize() / 2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-getXSize() / 2, -getYSize() / 2, -getZSize() / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(getXSize() / 2, -getYSize() / 2, -getZSize() / 2);
		glEnd();

	glPopMatrix();
}