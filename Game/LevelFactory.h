#ifndef LEVELFACTORY_HEADER
#define LEVELFACTORY_HEADER

#include "Level.h"

/*  
 * Procedurally generates a level based on a seed.
 */
class LevelFactory
{
public:
	/*
	 * Constructor.
	 * int seed - The seed to use for level generation.
	 */
	LevelFactory(int seed);

	/* Actually generates the level. */
	void generate();
	
	/* Returns the generated level. */
	Level* getLevel();
private:
	/* The last random number generated. */
	int randIteration;
	/* The initial random number (the seed) */
	int seed;
	/* The level that is being generated. */
	Level level;
	/* Generates random numbers. */
	float generateRandom();
	/* Determines what the next object to be placed in the level should be.
	 * LevelObject lastObject - The last object that was placed in the level.
	 */
	LevelObject& chooseNextObject(LevelObject lastObject);
};

#endif