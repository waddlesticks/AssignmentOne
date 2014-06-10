#pragma once

class Enemy
{
public:
	Enemy();
	Enemy(unsigned int a_iEnemySpriteID, float a_fPositionX, float a_fPositionY, float a_fVelocityX, float a_fVelocityY);
	~Enemy();

	unsigned int iEnemySpriteID;
	float fPositionX;
	float fPositionY;
	float fVelocityX;
	float fVelocityY;

	void Update(float fDeltaT);
	void Move();
	void Draw();
	void Destroy();

	bool bEnemyActive;

private:


};

