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
	void Update(float fDeltaT);
	void Shoot(unsigned int iBulletSpriteID);
	void PlayerDeath();


	int iLives;
	int iScore;

	
	unsigned int iSpriteID;
	float fPositionX;
	float fPositionY;
	
//	char *cHighScore;

private:
	unsigned int iMoveLeftKey;
	unsigned int iMoveRightKey;
	unsigned int iMoveUpKey;
	unsigned int iMoveDownKey;
	unsigned int iLeftMovementExtreme;
	unsigned int iRightMovementExtreme;
	unsigned int iTopMovementExtreme;
	unsigned int iBottomeMovementExtreme;
	unsigned int iShootKey;
	float fMaxReloadTime;
	float fCurrentReloadTime;
	float fPlayerVel;
};

