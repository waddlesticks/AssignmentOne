#pragma once
class Bullet
{
public:
	Bullet();
	Bullet(int a_iSpriteID);
	~Bullet();

	unsigned int iSpriteID;
	float fPositionX;
	float fPositionY;
	
	float fVelocityX;
	float fVelocityY;

	bool bIsActive;

	void Update(float fDeltaT);
	void Draw();
	void InitialiseBullet(float fPositionX, float fPositionY, float fVelocityX, float fVelocityY, unsigned int iSpriteID);

};

