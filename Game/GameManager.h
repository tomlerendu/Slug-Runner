#ifndef GAMEMANAGER_HEADER
#define GAMEMANAGER_HEADER

#include "TextureManager.h"
#include "InputManager.h"

class GameObject;

/*
 * Manages the game.
 * In charge of scenes, textures and inputs.
 */
class GameManager
{
public:
	GameManager();
	/* Names of scenes in the game */
	enum Scene { menu, play };

	/* Imports the textures from disk into openGL using the texture manager */
	void setupTextures();
	/* Returns the texture manager */
	TextureManager& getTextureManager();
	/* Returns the input manager */
	InputManager& getInputManager();

	/* Change the scene
	 * Scene sceneName - the enumerated name of the scene
	 * long data - any data that needs to be passed to the scene
	 */
	void changeScene(Scene sceneName, long data);
	
	/* Return the current tick of the game */
	int getTick();
	/* Update the game before rendering */
	void update(int tick);
	/* Render the game to the screen*/
	void render();
private:
	/* Manages textures (loads textures from disk, assigns string ID to each texture)*/
	TextureManager textureManager;
	/* Manages user input (key presses, mouse clicks) */
	InputManager inputManager;
	/* The current tick of the game*/
	int tick;
	/* A reference to the currently active seen that should be updated and rendered */
	GameObject *activeScene;
};

#endif