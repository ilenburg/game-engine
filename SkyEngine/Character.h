#pragma once

#include "Entity.h"

class Character : public Entity
{
public:

	glm::vec2 pos2D;
	glm::vec2 vel2D;
	glm::vec2 acc2D;
	float radius;
	float mass;
};