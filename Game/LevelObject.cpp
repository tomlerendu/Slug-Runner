#include "LevelObject.h"

LevelObject::LevelObject()
{
}

void LevelObject::setPosition(float x, float y, float z)
{
	this->xPos = x;
	this->yPos = y;
	this->zPos = z;
}

void LevelObject::setSize(float x, float y, float z)
{
	this->xSize = x;
	this->ySize = y;
	this->zSize = z;
}

float LevelObject::getMaxX()
{
	return xPos + (xSize / 2);
}

float LevelObject::getMinX()
{
	return xPos - (xSize / 2);
}

float LevelObject::getMaxY()
{
	return yPos + (ySize / 2);
}

float LevelObject::getMinY()
{
	return yPos - (ySize / 2);
}

float LevelObject::getMaxZ()
{
	return zPos + (zSize / 2);
}

float LevelObject::getMinZ()
{
	return zPos - (zSize / 2);
}

float LevelObject::getXPos()
{
	return xPos;
}

float LevelObject::getYPos()
{
	return yPos;
}

float LevelObject::getZPos()
{
	return zPos;
}

float LevelObject::getXSize()
{
	return xSize;
}

float LevelObject::getYSize()
{
	return ySize;
}

float LevelObject::getZSize()
{
	return zSize;
}