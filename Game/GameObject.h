#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER

#include "GameManager.h"

/* A blueprint for an object that appears on the game screen.
 * No actual implementation, just for structual purposes.
 */
class GameObject
{
public:
	/* Updates the object. Could update size, position or do colision detection.
	 * GameManager gameManager - A reference to the game manager
	 */
	virtual void update(GameManager *gameManager);

	/* Renders the object.
	* GameManager gameManager - A reference to the game manager
	*/
	virtual void render(GameManager *gameManager);
};

#endif