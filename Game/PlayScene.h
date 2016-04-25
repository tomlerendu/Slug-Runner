#ifndef PLAYSCENE_HEADER
#define PLAYSCENE_HEADER

#include "GameManager.h"
#include "Level.h"
#include <time.h>
#include <string>

class PlayScene : public GameObject
{
	Level *level;
	int startTime = -1;
	std::string elapsedTime;
public:
	void setLevel(Level *level);
	void update(GameManager *gameManager);
	void render(GameManager *gameManager);
	//xPos and zPos and rot are temp until a character object is implemented
	float xPos = 0;
	float zPos = 0;
	float rot = 0;
};

#endif