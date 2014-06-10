#include "Bullet.h"
#include "AIE.h"


Bullet::Bullet()
{
	this->fPositionX = 0;
	this->fPositionY = 0;
	this->iBulletSpriteID = 0;
	this->bIsActive = false;
	this->fMaxBulHeight = 800;
}

Bullet::Bullet(int iBulletSpriteID)
{
	this->iBulletSpriteID = iBulletSpriteID;
	this->fPositionX = 100;
	this->fPositionY = 100;
	this->fMaxBulHeight = 800;
}


void Bullet::Update(float fDeltaT)
{
	if( bIsActive == true )
	{
		fPositionX += fVelocityX * fDeltaT;
		fPositionY += fVelocityY * fDeltaT;
		if(fPositionY > fMaxBulHeight )
		{
			bIsActive = false;
		}
	}
}

void Bullet::Destroy()
{
	fPositionX = 10000;
	fPositionY = 10000;
	bIsActive = false;
}

void Bullet::InitialiseBullet(float fPositionX, float fPositionY, float fVelocityX, float fVelocityY, unsigned int iBulletSpriteID)
{
	this->fPositionX = fPositionX;
	this->fPositionY = fPositionY;
	this->fVelocityX = fVelocityX;
	this->fVelocityY = fVelocityY;

	this->iBulletSpriteID = iBulletSpriteID;

	bIsActive = true;
}

void Bullet::Draw()
{
	MoveSprite(iBulletSpriteID, fPositionX, fPositionY);
	DrawSprite(this->iBulletSpriteID);
}

Bullet::~Bullet()
{
}
