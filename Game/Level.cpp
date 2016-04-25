#include "Level.h"

void Level::addObject(LevelObject object)
{
	objects.push_back(object);
}

std::vector<LevelObject> Level::getObjects()
{
	return objects;
}