#ifndef STARTBLOCK_HEADER
#define STARTBLOCK_HEADER

#include "LevelObject.h"
#include "GameManager.h"
#include "Block.h"
#include <glew.h>

class StartBlock : public Block
{
	GLuint flagPoleVBO;
	GLuint flagVBO;
public:
	StartBlock();
	void render(GameManager *gameManager);
};

#endif