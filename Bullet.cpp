#include "Bullet.h"
#include "AIE.h"


Bullet::Bullet()
{
	this->fPositionX = 0;
	this->fPositionY = 0;
	this->iSpriteID = 0;
}

Bullet::Bullet(int a_iSpriteID)
{
	this->iSpriteID = a_iSpriteID;
	this->fPositionX = 100;
	this->fPositionY = 100;
	
}

void Bullet::Update(float fDeltaT)
{
	if( bIsActive == true)
	{
		fPositionX += fVelocityX * fDeltaT;
		fPositionY += fVelocityY * fDeltaT;
	}
}

void Bullet::InitialiseBullet(float fPositionX, float fPositionY, float fVelocityX, float fVelocityY, unsigned int iSpriteID)
{
	this->fPositionX = fPositionX;
	this->fPositionY = fPositionY;
	this->fVelocityX = fVelocityX;
	this->fPositionY = fVelocityY;

	bIsActive = true;
}

void Bullet::Draw()
{
	MoveSprite(iSpriteID, fPositionX, fPositionY);
	DrawSprite(this->iSpriteID);
}

Bullet::~Bullet()
{
}
