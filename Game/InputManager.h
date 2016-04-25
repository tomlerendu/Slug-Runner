#include <queue>
#include <utility>

/* Manages user input.
 * Handles key presses, special key presses (arrow keys, backspace) and mouse clicks.
 */
class InputManager
{
public:
	/* Special keys that do not have character codes. */
	enum Keys {BACKSPACE, LEFT_ARROW, RIGHT_ARROW, UP_ARROW, DOWN_ARROW};

	/* Add a special key press made by the user to the input manager.
	 * Keys key - The key that was pressed
	 */
	void addSpecialKeyPress(Keys key);

	/* Add a key press made by the user to the input manager.
	 * unsigned char key - The ASCII key code of the key 
	 */
	void addKeyPress(unsigned char key);

	/* Add a mouse click made by the user to the input manager.
	 * Clicks are converted into a % of how far into the window they ar.
	 * int x - The x position of the mouse click in the window
	 * int y - The y position of the mouse click in the window
	 */
	void addMouseClick(int x, int y);

	/* Return the queue of special key presses */
	std::queue<Keys>& getSpecialKeyPresses();
	/* Return the queue of key presses */
	std::queue<unsigned char>& getKeyPresses();
	/* Return the queue of mouse clicks */
	std::queue<std::pair<int, int>>& getMouseClicks();
private:
	/* Holds special key presses */
	std::queue<Keys> specialKeyPresses;
	/* Holds key presses */
	std::queue<unsigned char> keyPresses;
	/* Holds mouse clicks */
	std::queue<std::pair<int, int>> mouseClicks;
};