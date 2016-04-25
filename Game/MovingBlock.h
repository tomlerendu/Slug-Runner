#ifndef MOVINGBLOCK_HEADER
#define MOVINGBLOCK_HEADER

#include "LevelObject.h"
#include "GameManager.h"

class MovingBlock : public LevelObject
{
public:
	enum MoveDirection {MOVE_X, MOVE_Z};
	MovingBlock();
	void setDirection(MoveDirection direction);
	void setSpeed(int speed);
	void update(GameManager *gameManager);
	void render(GameManager *gameManager);
private:
	MoveDirection direction;
	int speed;
	float blockSize;
	float blockX;
	float blockZ;
};

#endif