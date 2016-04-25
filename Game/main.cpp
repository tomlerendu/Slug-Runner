#include <iostream>
#include <time.h>
#include "Block.h"
#include "MovingBlock.h"
#include "GameManager.h"
#include <gl/glut.h>

GameManager gameManager;

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1280.0 / 720.0, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	gameManager.setupTextures();
	gameManager.changeScene(GameManager::Scene::menu, NULL);
	srand(time(NULL));
}

void updateScene()
{
	int time = glutGet(GLUT_ELAPSED_TIME);
	gameManager.update(time);

	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gameManager.render();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1280.0 / 720.0, 1.0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_UP)
		gameManager.getInputManager().addMouseClick(x, y);
}

void pmotion(int x, int y)
{
	
}

void keyboard(unsigned char key, int x, int y)
{
	gameManager.getInputManager().addKeyPress(key);
	glutPostRedisplay();
}

void special(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: gameManager.getInputManager().addSpecialKeyPress(InputManager::Keys::LEFT_ARROW); break;
	case GLUT_KEY_UP: gameManager.getInputManager().addSpecialKeyPress(InputManager::Keys::UP_ARROW); break;
	case GLUT_KEY_RIGHT: gameManager.getInputManager().addSpecialKeyPress(InputManager::Keys::RIGHT_ARROW); break;
	case GLUT_KEY_DOWN: gameManager.getInputManager().addSpecialKeyPress(InputManager::Keys::DOWN_ARROW); break;
	}

	glutPostRedisplay();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(864, 486);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 864) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 486) / 2);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("SlugRunner");

	init();

	glutMouseFunc(mouse);
	glutPassiveMotionFunc(pmotion);
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
	
	glutReshapeFunc(reshape);
	glutIdleFunc(updateScene);
	glutDisplayFunc(display);

	glutMainLoop();
}