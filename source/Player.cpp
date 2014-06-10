#include "Player.h"
#include "AIE.h"
#include <fstream>
#include <iostream>


Player::Player()
{
	this->fPositionX = 0;
	this->fPositionY = 0;
	this->iSpriteID = 0;
	this->iMoveLeftKey = 0;
	this->iMoveRightKey = 0;
	this->iMoveUpKey = 0;
	this->iMoveDownKey = 0;
	this->iShootKey = 0;
	this->fMaxReloadTime = .5f;
	this->fCurrentReloadTime = 0;
	this->iScore = 0;
	this->iLeftMovementExtreme = 0;
	this->iRightMovementExtreme = 0;
	this->iTopMovementExtreme = 0;
	this->iBottomeMovementExtreme = 0;
	this->fPlayerVel = 0;
	this->iLives = 0;

}

Player::Player(int a_iSpriteID)
{
	this->iSpriteID = a_iSpriteID;
	this->fPositionX = 10;
	this->fPositionY = 10;
	this->iMoveLeftKey = 'A';
	this->iMoveRightKey = 'D';
	this->iMoveUpKey = 'W';
	this->iMoveDownKey = 'S';
	this->iShootKey = KEY_SPACE;
	this->fMaxReloadTime = .5f;
	this->fCurrentReloadTime = 0;
	this->iScore = 0;
	this->iLeftMovementExtreme = 10;
	this->iRightMovementExtreme = 662;
	this->iTopMovementExtreme = 770;
	this->iBottomeMovementExtreme = 10;
	this->fPlayerVel = .25f;
	this->iLives = 3;

	
}

void Player::Shoot(unsigned int iBulletSpriteID)
{
	if(IsKeyDown(iShootKey) && fCurrentReloadTime >= fMaxReloadTime)
	{
		GetInactiveBullet().InitialiseBullet(fPositionX, fPositionY, 0, 250, iBulletSpriteID);
		fCurrentReloadTime = 0;
	}
}

void Player::PlayerDeath()
{
//	char *cHighScore = ""; 
	char *cHighScore = " ";
	int iHighScore = 0;
	std::ifstream input("Highscores.txt");

	if( input )
	{
		input.getline(cHighScore, 256);

		iHighScore = atoi (cHighScore);
	}

	std::cout << iHighScore << std::endl;
	
}

Bullet& Player::GetInactiveBullet()
{
	for(int i = 0; i < MAX_BULLETS; i++)
	{
		if(!bullets[i].bIsActive)
		{
			return bullets[i];
		}
	}

	return bullets[0];
}

Player::~Player()
{
}


void Player::Draw()
{
	MoveSprite(iSpriteID, fPositionX, fPositionY);
	DrawSprite(this->iSpriteID);

}

void Player::Update(float fDeltaT)
{
	fCurrentReloadTime += fDeltaT;

	if(IsKeyDown (iMoveLeftKey))
	{
		fPositionX -= fPlayerVel;
		if( fPositionX <= iLeftMovementExtreme)
		{
			fPositionX = 10.f;
		}
	}
	if( IsKeyDown (iMoveRightKey))
	{
		fPositionX += fPlayerVel;
		if( fPositionX >= iRightMovementExtreme)
		{
			fPositionX = 662.f;
		}
	}
	if(IsKeyDown (iMoveUpKey))
	{
		fPositionY += fPlayerVel;
		if( fPositionY >= iTopMovementExtreme)
		{
			fPositionY = 770.f;
		}
	}
	if(IsKeyDown (iMoveDownKey))
	{
		fPositionY -= fPlayerVel;
		if( fPositionY <= iBottomeMovementExtreme)
		{
			fPositionY = 10.f;
		}
	}

}