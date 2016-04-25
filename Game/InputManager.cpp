#include "InputManager.h"
#include <iostream>
#include <gl/glut.h>
#include <math.h>
#include <ctype.h>


void InputManager::addSpecialKeyPress(Keys key)
{
	specialKeyPresses.push(key);
}

void InputManager::addKeyPress(unsigned char key)
{
	keyPresses.push(tolower(key));
}

void InputManager::addMouseClick(int x, int y)
{
	int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	int xPos = round((float)x / (float)windowWidth * 1000);
	int yPos = round((float)y / (float)windowHeight * 1000);

	std::pair<int, int> mouse = { xPos, yPos };
	mouseClicks.push(mouse);
}

std::queue<InputManager::Keys>& InputManager::getSpecialKeyPresses()
{
	return specialKeyPresses;
}

std::queue<unsigned char>& InputManager::getKeyPresses()
{
	return keyPresses;
}

std::queue<std::pair<int, int>>& InputManager::getMouseClicks()
{
	return mouseClicks;
}