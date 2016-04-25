#include "GameManager.h"
#include "PlayScene.h"
#include "MenuScene.h"
#include "LevelFactory.h"
#include "gl/glut.h"
#include "GameObject.h"

GameManager::GameManager()
{
}

void GameManager::setupTextures()
{
	//Load the textures
	textureManager.addTexture("block_top.bmp", "blockTop");
	textureManager.addTexture("block_side.bmp", "blockSide");
	textureManager.addTexture("pole_wood.bmp", "poleWood");
	textureManager.addTexture("pole_start_flag.bmp", "poleStartFlag");
	textureManager.addTexture("pole_end_flag.bmp", "poleEndFlag");
	textureManager.addTexture("sky.bmp", "sky");
	textureManager.addTexture("logo.bmp", "logo");
	textureManager.addTexture("play.bmp", "play");
	textureManager.addTexture("random.bmp", "random");
}

TextureManager& GameManager::getTextureManager()
{
	return textureManager;
}

InputManager& GameManager::getInputManager()
{
	return inputManager;
}

void GameManager::changeScene(Scene sceneName, long data)
{
	delete activeScene;

	//Change to the Play scene
	if (sceneName == Scene::play)
	{
		LevelFactory levelFactory(data);
		levelFactory.generate();
		Level *level = levelFactory.getLevel();
		PlayScene *scene = new PlayScene();
		scene->setLevel(level);
		activeScene = scene;
	}
	//Change to the menu scene
	else if (sceneName == Scene::menu)
	{
		MenuScene *scene = new MenuScene();
		activeScene = scene;
	}
}

int GameManager::getTick()
{
	return tick;
}

void GameManager::update(int tick)
{
	//To keep all game objects consistent store the tick and use it to update each object
	this->tick = tick;
	activeScene->update(this);
}

void GameManager::render()
{
	activeScene->render(this);
}