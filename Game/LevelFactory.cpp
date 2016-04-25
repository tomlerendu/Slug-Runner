#include "LevelFactory.h"
#include "Level.h"
#include "Block.h"
#include "Space.h"
#include "LevelObject.h"
#include "stdint.h"
#include <typeinfo>
#include <iostream>

LevelFactory::LevelFactory(int seed, Difficulty difficulty)
{
	this->seed = seed;
	this->difficulty = difficulty;
	this->randIteration = 1;
}

float LevelFactory::generateRandom()
{
	//Random number generation between 0 and 1 based on seed
	uint32_t seed = (uint32_t) this->seed;
	seed ^= seed << 13;
	seed ^= seed >> 17;
	seed ^= seed << 5;
	this->seed = seed;
	return abs((float)this->seed / (float)INT_MAX);
}

Level* LevelFactory::getLevel()
{
	return &level;
}

void LevelFactory::generate()
{
	enum directions { X_INC, X_DEC, Z_INC, Z_DEC };

	for (int i = 0; i < 20; i++)
	{
		LevelObject obj = chooseNextObject(Block());
		obj.setPosition(0, 0, 0);
		obj.setSize(10, 10, 10);
		level.addObject(obj);
	}
}

LevelObject& LevelFactory::chooseNextObject(LevelObject lastObject)
{
	float rand = generateRandom();

	LevelObject nextObject;

	if (rand < 0.5 && typeid(lastObject).name() != "Space")
		Space nextObject;
	else
		Block nextObject;

	return nextObject;
}