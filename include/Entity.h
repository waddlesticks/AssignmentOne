#pragma once
class Entity
{
public:
	Entity(void);
	~Entity(void);


	void SetSize(float fWidth, float fHeight);

	float GetWidth();
	float GetHeight();

private:

	unsigned int iSpriteID;

	float fWidth;
	float fHeight;
};



