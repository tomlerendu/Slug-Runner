#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include <vector>
#include "LevelObject.h"

/* A model of a procedurally genereated level
 * Stores all of the objects in the level as well as the start and finish points.
 */
class Level
{
	/* A vector of objects that make up the level */
	std::vector<LevelObject> objects;
public:
	/* Add an object to the level
	 * LevelObject object - The object to be added to the level
	 */
	void addObject(LevelObject object);
	/* Get the objects that make up the level */
	std::vector<LevelObject> getObjects();
};

#endif