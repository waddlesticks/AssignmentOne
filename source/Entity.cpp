#include "Entity.h"


Entity::Entity(void)
{
}


void Entity::SetSize(float fWidth, float fHeight)
{
	this->fWidth = fWidth;
	this->fHeight = fHeight;
}

float Entity::GetWidth()
{
	return fWidth;
}

float Entity::GetHeight()
{
	return fHeight;
}

Entity::~Entity(void)
{
}
