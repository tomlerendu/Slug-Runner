#include "TextureManager.h"
#include "BMPLoader.h"
#include <iostream>
#include <cstdlib>
#include "gl/glut.h"

void TextureManager::addTexture(std::string fileName, std::string textureId)
{
	//Generate a texture ID
	unsigned int id;
	glGenTextures(1, &id);

	//Add id and name to the map
	textureIds.insert({ textureId, id });

	//Load the image
	BMPClass bmp;
	BMPLoad(fileName, bmp);

	//Bind
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, bmp.width, bmp.height, 0, GL_RGB, GL_UNSIGNED_BYTE, bmp.bytes);
}

unsigned int TextureManager::getTexture(std::string textureId)
{
	return textureIds.at(textureId);
}