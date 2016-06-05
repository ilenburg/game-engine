#pragma once

#include "Entity.h"

class Foreground : public Entity
{
public:
	Foreground();
	Foreground(int p1X, int p1Y, int p4X, int p4Y);

	glm::vec2 p1;
	glm::vec2 p2;
	glm::vec2 p3;
	glm::vec2 p4;
	glm::vec2 normal;
};