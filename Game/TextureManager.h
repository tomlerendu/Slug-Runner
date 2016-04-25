#ifndef TEXTUREMANAGER_HEADER
#define TEXTUREMANAGER_HEADER

#include <string>
#include <map>

class TextureManager
{
	std::map<std::string, unsigned int> textureIds;
public:
	void addTexture(std::string fileName, std::string textureId);
	unsigned int getTexture(std::string textureId);
};

#endif