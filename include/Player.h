#pragma once
#include "Bullet.h"

const int MAX_BULLETS = 20;

class Player
{
public:
	Player();
	Player(int a_iSpriteID);
	~Player();

	Bullet bullets[MAX_BULLETS];
	Bullet &GetInactiveBullet();
	


	void SetMovementKeys(unsigned int iMoveLeftKey, unsigned int iMoveRightKey, unsigned int iMoveUpKey, unsigned int iMoveDownKey);
	void SetMovementExtremes(unsigned int iLeftMovementExtreme, unsigned int iRightMovementExtreme);

	void Draw();
	void Update();
	void Shoot(unsigned int a_iSpriteID, float fDeltaT);



	int lives;
	unsigned int iSpriteID;
	float fPositionX;
	float fPositionY;

private:
	unsigned int iMoveLeftKey;
	unsigned int iMoveRightKey;
	unsigned int iMoveUpKey;
	unsigned int iMoveDownKey;
	unsigned int iLeftMovementExtreme;
	unsigned int iRightMovementExtreme;
	unsigned int iShootKey;

};

