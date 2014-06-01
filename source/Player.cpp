#include "Player.h"
#include "AIE.h"


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
}

Player::Player(int a_iSpriteID)
{
	this->iSpriteID = a_iSpriteID;
	this->fPositionX = 10;
	this->fPositionY = 10;
	
}

void Player::Shoot(unsigned int a_iSpriteID, float fDeltaT)
{
	if(IsKeyDown(KEY_SPACE))
	{
		GetInactiveBullet().InitialiseBullet(fPositionX, fPositionY, 0, 50, iSpriteID);
	}
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

void Player::Update()
{
	if(IsKeyDown ('A'))
	{
		fPositionX -= .1f;
		if( fPositionX <= 10)
		{
			fPositionX = 10.f;
		}
	}
	if( IsKeyDown ('D'))
	{
		fPositionX += .1f;
		if( fPositionX >= 662)
		{
			fPositionX = 662.f;
		}
	}
	if(IsKeyDown ('W'))
	{
		fPositionY += .1f;
		if( fPositionY >= 770)
		{
			fPositionY = 770.f;
		}
	}
	if(IsKeyDown ('S'))
	{
		fPositionY -= .1f;
		if( fPositionY <= 10)
		{
			fPositionY = 10.f;
		}
	}

}