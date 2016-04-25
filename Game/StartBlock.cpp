#include "StartBlock.h"
#include <iostream>
#include <gl/glut.h>

StartBlock::StartBlock()
{
	GLfloat flag[] = {
		//Bottom
		-0.1, getYSize() * 1.4, 0.025,
		-0.8, getYSize() * 1.4, 0.025,
		-0.8, getYSize() * 1.4, -0.025,
		-0.1, getYSize() * 1.4, -0.025,
		//Top
		-0.1, getYSize() * 1.95, 0.025,
		-0.8, getYSize() * 1.95, 0.025,
		-0.8, getYSize() * 1.95, -0.025,
		-0.1, getYSize() * 1.95, -0.025,
		//Front
		-0.1, getYSize() * 1.4, 0.025,
		-0.8, getYSize() * 1.4, 0.025,
		-0.8, getYSize() * 1.95, 0.025,
		-0.1, getYSize() * 1.95, 0.025,
		//Back
		-0.1, getYSize() * 1.4, -0.025,
		-0.8, getYSize() * 1.4, -0.025,
		-0.8, getYSize() * 1.95, -0.025,
		-0.1, getYSize() * 1.95, -0.025,
		//Left
		-0.8, getYSize() * 1.95, 0.025,
		-0.8, getYSize() * 1.4, 0.025,
		-0.8, getYSize() * 1.4, -0.025,
		-0.8, getYSize() * 1.95, -0.025,
		//Right
		-0.1, getYSize() * 1.95, 0.025,
		-0.1, getYSize() * 1.4, 0.025,
		-0.1, getYSize() * 1.4, -0.025,
		-0.1, getYSize() * 1.95, -0.025
	};

	//Create a buffer for the flag object and send it to the video card
	glGenBuffers(1, &flagVBO);
	glBindBuffer(GL_ARRAY_BUFFER, flagVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(flagVBO), (void*) flagVBO, GL_STATIC_DRAW);
}

void StartBlock::render(GameManager *gameManager)
{
	Block::render(gameManager);

	glPushMatrix();

		glTranslatef(getXPos(), getYPos(), getZPos());

		GLfloat flagPole[] = {
			//Bottom
			0.1, getYSize() / 2, 0.1,
			- 0.1, getYSize() / 2, 0.1,
			- 0.1, getYSize() / 2, -0.1,
			0.1, getYSize() / 2, -0.1,
			//Top
			0.1, getYSize() * 2, 0.1,
			-0.1, getYSize() * 2, 0.1,
			-0.1, getYSize() * 2, -0.1,
			0.1, getYSize() * 2, -0.1,
			//Front
			0.1, getYSize() / 2, 0.1,
			-0.1, getYSize() / 2, 0.1,
			-0.1, getYSize() * 2, 0.1,
			0.1, getYSize() * 2, 0.1,
			//Back
			0.1, getYSize() / 2, -0.1,
			-0.1, getYSize() / 2, -0.1,
			-0.1, getYSize() * 2, -0.1,
			0.1, getYSize() * 2, -0.1,
			//Left
			-0.1, getYSize() * 2, 0.1,
			-0.1, getYSize() / 2, 0.1,
			-0.1, getYSize() / 2, -0.1,
			-0.1, getYSize() * 2, -0.1,
			//Right
			0.1, getYSize() * 2, 0.1,
			0.1, getYSize() / 2, 0.1,
			0.1, getYSize() / 2, -0.1,
			0.1, getYSize() * 2, -0.1
		};

		glVertexPointer(3, GL_FLOAT, 0, flagPole);
		glDrawArrays(GL_QUADS, 0, 24);

		GLfloat flag[] = {
			//Bottom
			-0.1, getYSize() * 1.4, 0.025,
			-0.8, getYSize() * 1.4, 0.025,
			-0.8, getYSize() * 1.4, -0.025,
			-0.1, getYSize() * 1.4, -0.025,
			//Top
			-0.1, getYSize() * 1.95, 0.025,
			-0.8, getYSize() * 1.95, 0.025,
			-0.8, getYSize() * 1.95, -0.025,
			-0.1, getYSize() * 1.95, -0.025,
			//Front
			-0.1, getYSize() * 1.4, 0.025,
			-0.8, getYSize() * 1.4, 0.025,
			-0.8, getYSize() * 1.95, 0.025,
			-0.1, getYSize() * 1.95, 0.025,
			//Back
			-0.1, getYSize() * 1.4, -0.025,
			-0.8, getYSize() * 1.4, -0.025,
			-0.8, getYSize() * 1.95, -0.025,
			-0.1, getYSize() * 1.95, -0.025,
			//Left
			-0.8, getYSize() * 1.95, 0.025,
			-0.8, getYSize() * 1.4, 0.025,
			-0.8, getYSize() * 1.4, -0.025,
			-0.8, getYSize() * 1.95, -0.025,
			//Right
			-0.1, getYSize() * 1.95, 0.025,
			-0.1, getYSize() * 1.4, 0.025,
			-0.1, getYSize() * 1.4, -0.025,
			-0.1, getYSize() * 1.95, -0.025
		};

		glVertexPointer(3, GL_FLOAT, 0, flag);
		glDrawArrays(GL_QUADS, 0, 24);

	glPopMatrix();
}