#ifndef MENUSCENE_HEADER
#define MENUSCENE_HEADER

#include "GameManager.h"
#include "GameObject.h"
#include <string>

class MenuScene : public GameObject
{
	float rotation;
	std::string seed;
public:
	MenuScene();
	void update(GameManager *gameManager);
	void render(GameManager *gameManager);
	void randomClicked();
	void playClicked(GameManager *gameManager);
};

#endif