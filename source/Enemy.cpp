#include "AIE.h"
#include "Enemy.h"
#include "Bullet.h"


Enemy::Enemy()
{
	this->iEnemySpriteID = 0;
	this->fPositionX = 0;
	this->fPositionY = 0;
	this->fVelocityX = 0;
	this->fVelocityY = 0;
	this->bEnemyActive = 0;
}

Enemy::Enemy(unsigned int a_iEnemySpriteID, float a_fPositionX, float a_fPositionY, float a_fVelocityX, float a_fVelocityY)
{
	this->iEnemySpriteID = a_iEnemySpriteID;
	this->fPositionX = a_fPositionX;
	this->fPositionY = a_fPositionY;
	this->fVelocityX = a_fVelocityX;
	this->fVelocityY = a_fVelocityY;
}


void Enemy::Update(float fDeltaT)
{
	if(bEnemyActive == false)
	{
		return;
	}
	fPositionX += fVelocityX * fDeltaT;
	fPositionY += fVelocityY * fDeltaT;
	
}

void Enemy::Destroy()
{
	fPositionX = 20000;
	fPositionY = 20000;
	bEnemyActive = false;
}

void Enemy::Move()
{

}

void Enemy::Draw()
{
	MoveSprite(iEnemySpriteID, fPositionX, fPositionY);
	DrawSprite(iEnemySpriteID);
}

Enemy::~Enemy()
{
}
