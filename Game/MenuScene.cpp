#include "MenuScene.h"
#include "gl/glut.h"
#include <iostream>

MenuScene::MenuScene()
{
	rotation = 0;
	seed = "";
}

void MenuScene::update(GameManager *gameManager)
{
	//Rotate the clouds
	rotation = (float)gameManager->getTick() / 150;
	if (rotation > 360)
		rotation -= 360;

	//Read numbers into the seed
	while (!gameManager->getInputManager().getKeyPresses().empty()) {
		unsigned char key = gameManager->getInputManager().getKeyPresses().back();
		//TODO: shoudl it be front or back???
		
		//Handle 0 to 9
		if ((key == '0' || key == '1' || key == '2' || key == '3' || key == '4' || key == '5' ||
			key == '6' || key == '7' || key == '8' || key == '9') && seed.length() < 9)
			seed += key;

		//Handle backspace
		if ((unsigned int)key == 8 && seed.length() != 0)
			seed = seed.substr(0, seed.size() - 1);

		gameManager->getInputManager().getKeyPresses().pop();
	}
	
	//Handle clicks
	while (!gameManager->getInputManager().getMouseClicks().empty()) {
		std::pair<int, int> click = gameManager->getInputManager().getMouseClicks().front();
		
		//Random button
		if (click.first >= 616 && click.first <= 787 && click.second >= 461 && click.second <= 560)
			randomClicked();

		//Play button
		if (click.first >= 387 && click.first <= 613 && click.second >= 646 && click.second <= 805)
			playClicked(gameManager);

		gameManager->getInputManager().getMouseClicks().pop();
	}
}

void MenuScene::render(GameManager *gameManager)
{
	glClearColor(130.0 / 255.0, 181.0 / 255.0, 229.0 / 255.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();
		glPushMatrix();

			//Rotate the camera around
			gluLookAt(0, 3, 6, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			glRotatef(rotation, 0.0, 1.0, 0.0);

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

		glPopMatrix();

		//Add the logo
		glBindTexture(GL_TEXTURE_2D, gameManager->getTextureManager().getTexture("logo"));
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0);
			glVertex3f(-10, 10, -60);
			glTexCoord2f(0, 0.5);
			glVertex3f(-10, 20, -60);
			glTexCoord2f(1, 0.5);
			glVertex3f(10, 20, -60);
			glTexCoord2f(1, 0);
			glVertex3f(10, 10, -60);
		glEnd();
	
		//Add the game setup options
		glBegin(GL_QUADS);
			glColor3f(0.85f, 0.85f, 0.85f);
			glVertex3f(-30, -18, -60);
			glVertex3f(-30, 8, -60);
			glVertex3f(30, 8, -60);
			glVertex3f(30, -18, -60);
		glEnd();

		//Add the play button
		glColor3f(1.0f, 1.0f, 1.0f);
		glBindTexture(GL_TEXTURE_2D, gameManager->getTextureManager().getTexture("play"));
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0);
			glVertex3f(-10, -15, -59);
			glTexCoord2f(0, 0.37);
			glVertex3f(-10, -7, -59);
			glTexCoord2f(1, 0.37);
			glVertex3f(10, -7, -59);
			glTexCoord2f(1, 0);
			glVertex3f(10, -15, -59);
		glEnd();

		//Add the text box
		glBegin(GL_QUADS);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(-25, 2, -59);
			glVertex3f(-25, -3, -59);
			glVertex3f(10, -3, -59);
			glVertex3f(10, 2, -59);
		glEnd();

		//Add the random button
		glBindTexture(GL_TEXTURE_2D, gameManager->getTextureManager().getTexture("random"));
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0);
			glVertex3f(10, -3, -59);
			glTexCoord2f(0, 0.325);
			glVertex3f(10, 2, -59);
			glTexCoord2f(1, 0.325);
			glVertex3f(25, 2, -59);
			glTexCoord2f(1, 0);
			glVertex3f(25, -3, -59);
		glEnd();

		//Add the seed text
		glPushMatrix();
			glTranslatef(-24, -2, -58);
			glScalef(0.03, 0.03, 0.03);
			glColor3f(0.75, 0.42, 0.0);
			for (unsigned int i=0; i<seed.size(); i++)
				glutStrokeCharacter(GLUT_STROKE_ROMAN, seed[i]);
		glPopMatrix();
	glPopMatrix();
}

void MenuScene::randomClicked()
{
	seed = "";
	for (int i = 0; i < 9; i++) {
		unsigned num = rand() % 10;
		seed += std::to_string(num);
	}
}

void MenuScene::playClicked(GameManager *gameManager)
{
	if (seed.size() != 0)
	{
		long num = atol(seed.c_str());
		gameManager->changeScene(GameManager::play, num);
	}
}