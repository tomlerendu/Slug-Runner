#ifndef LEVELOBJECT_HEADER
#define LEVELOBJECT_HEADER

#include "GameObject.h"

/* LevelObject is a base class for all objects in a level.
 * It has methods to get and set the position and size of an object.
 */
class LevelObject : public GameObject
{
public:
	LevelObject();
	/*
	 * Set the position of an object in the level
	 * float x - The center position of the object on the x-axis
	 * float y - The center position of the object on the y-axis
	 * float z - The center position of the object on the z-axis
	 */
	void setPosition(float x, float y, float z);
	/*
	 * Set the size of the object in the level
	 * float x - The length along the x axis
	 * float y - The length along the y axis
	 * float z - The length along the z axis
	 */
	void setSize(float x, float y, float z);
	float getMaxX();
	float getMinX();
	float getMaxY();
	float getMinY();
	float getMaxZ();
	float getMinZ();
	float getXPos();
	float getYPos();
	float getZPos();
	float getXSize();
	float getYSize();
	float getZSize();
private:
	float xPos;
	float yPos;
	float zPos;
	float xSize;
	float ySize;
	float zSize;
};

#endif