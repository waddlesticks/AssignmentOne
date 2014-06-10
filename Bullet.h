#pragma once
class Bullet
{
public:
	Bullet();
	Bullet(int iBulletSpriteID);
	~Bullet();

	unsigned int iBulletSpriteID;
	float fPositionX;
	float fPositionY;
	float fMaxBulHeight;
	float fLowBulHeight;
	
	float fVelocityX;
	float fVelocityY;

	bool bIsActive;

	void Update(float fDeltaT);
	void Draw();
	void InitialiseBullet(float fPositionX, float fPositionY, float fVelocityX, float fVelocityY, unsigned int iSpriteID);
	void Destroy();

};

