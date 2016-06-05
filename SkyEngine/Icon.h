#pragma once

#include "Entity.h"

class Icon : public Entity
{
public:
	Icon();
	Icon(int x, int y, float size);
	Icon(int x, int y, float size, int sVar);

	glm::vec2 pos2D;
	float radius;
};