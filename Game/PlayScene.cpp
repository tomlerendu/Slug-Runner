#include "PlayScene.h"
#include "MovingBlock.h"
#include "StartBlock.h"
#include "gl/glut.h"
#include <iostream>

void PlayScene::setLevel(Level* level)
{
	this->level = level;
}

void PlayScene::update(GameManager *gameManager)
{
	//If the time needs to be initialised do it
	if (startTime == -1)
		startTime = gameManager->getTick();

	//Figure out the elapsed time
	elapsedTime = std::to_string((gameManager->getTick() - startTime) / 80);

	//Handle game input
	while (!gameManager->getInputManager().getSpecialKeyPresses().empty()) {
		InputManager::Keys key = gameManager->getInputManager().getSpecialKeyPresses().front();

		switch (key)
		{
		case InputManager::Keys::LEFT_ARROW: rot += 3; break;
		case InputManager::Keys::RIGHT_ARROW: rot -= 3; break;
		}

		gameManager->getInputManager().getSpecialKeyPresses().pop();
	}

	while (!gameManager->getInputManager().getKeyPresses().empty()) {
		unsigned char key = gameManager->getInputManager().getKeyPresses().back();
		//TODO: shoudl it be front or back???
		
		switch (key)
		{
		case 'a': xPos += 0.1; break;
		case 'd': xPos -= 0.1; break;
		case 's': zPos -= 0.1; break;
		case 'w': zPos += 0.1; break;
		}

		gameManager->getInputManager().getKeyPresses().pop();
	}
}

void PlayScene::render(GameManager *gameManager)
{
	glClearColor(130.0 / 255.0, 181.0 / 255.0, 229.0 / 255.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();

		//Temp code for moving about before character is implemented
		gluLookAt(0, 3, 6, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glTranslatef(xPos, 0.0, zPos);
		glRotatef(rot, 0.0, 1.0, 0.0);

		for (unsigned i = 0; i < level->getObjects().size(); i++)
		{
			level->getObjects().at(i).render(gameManager);
		}

		//Draw the sky
		glBindTexture(GL_TEXTURE_2D, gameManager->getTextureManager().getTexture("sky"));
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0);
			glVertex3f(-500, -50, -500);
			glTexCoord2f(0, 1);
			glVertex3f(-500, -50, 500);
			glTexCoord2f(1, 1);
			glVertex3f(500, -50, 500);
			glTexCoord2f(1, 0);
			glVertex3f(500, -50, -500);
		glEnd();

		//These blocks will be created randomly in the final version
		MovingBlock block;
		block.setPosition(0, 0, 0);
		block.setSize(6.0, 1.0, 1.0);
		block.setDirection(MovingBlock::MoveDirection::MOVE_X);
		block.setSpeed(45);
		block.update(gameManager);
		block.render(gameManager);

		StartBlock block2;
		block2.setPosition(0, 0, -1);
		block2.setSize(6.0, 1.0, 1.0);
		block2.update(gameManager);
		block2.render(gameManager);

		StartBlock block3;
		block3.setPosition(0, 0, -7);
		block3.setSize(6.0, 1.0, 6.0);
		block3.update(gameManager);
		block3.render(gameManager);

		StartBlock block4;
		block4.setPosition(0, -5, -1);
		block4.setSize(1.0, 1.0, 1.0);
		block4.update(gameManager);
		block4.render(gameManager);

		StartBlock block5;
		block5.setPosition(0, -5, -2);
		block5.setSize(1.0, 2.0, 1.0);
		block5.update(gameManager);
		block5.render(gameManager);

		MovingBlock block6;
		block6.setPosition(0, -1, -10);
		block6.setSize(6.0, 1.0, 8.0);
		block6.setDirection(MovingBlock::MoveDirection::MOVE_Z);
		block6.setSpeed(80);
		block6.update(gameManager);
		block6.render(gameManager);

		MovingBlock block7;
		block7.setPosition(7, 0, -5);
		block7.setSize(7.0, 1.0, 1.0);
		block7.setDirection(MovingBlock::MoveDirection::MOVE_X);
		block7.setSpeed(50);
		block7.update(gameManager);
		block7.render(gameManager);

		MovingBlock block8;
		block8.setPosition(0, 0, 2);
		block8.setSize(6.0, 1.0, 1.0);
		block8.setDirection(MovingBlock::MoveDirection::MOVE_X);
		block8.setSpeed(3);
		block8.update(gameManager);
		block8.render(gameManager);

		MovingBlock block9;
		block9.setPosition(0, 0, 1);
		block9.setSize(6.0, 1.0, 1.0);
		block9.setDirection(MovingBlock::MoveDirection::MOVE_X);
		block9.setSpeed(86);
		block9.update(gameManager);
		block9.render(gameManager);

	glPopMatrix();

	//Print the time elapsed
	//Disable the z buffer so it always appears on top
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
		//Render the background for the timer
		glColor3f(0.32, 0.21, 0.09);
		glBegin(GL_QUADS);
			glVertex3f(-43.5 + elapsedTime.size() * 3.6 + 0.4, 24, -60);
			glVertex3f(-43.5 + elapsedTime.size() * 3.6 + 0.4, 19, -60);
			glVertex3f(-43.5, 19, -60);
			glVertex3f(-43.5, 24, -60);
		glEnd();

		//Render the font for the timer
		glColor3f(1.0, 1.0, 1.0);
		glPushMatrix();
			glTranslatef(-42.2, 19.6, -59);
			glScalef(0.03, 0.03, 0.03);
			for (unsigned int i = 0; i<elapsedTime.size(); i++) {
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, elapsedTime[i]);
			}
		glPopMatrix();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
}