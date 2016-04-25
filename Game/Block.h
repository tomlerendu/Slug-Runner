#ifndef BLOCK_HEADER
#define BLOCK_HEADER

#include "LevelObject.h"
#include "GameManager.h"

class Block : public LevelObject
{
public:
	void render(GameManager *gameManager);
};

#endif