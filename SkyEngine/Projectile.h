#pragma once

#include "Character.h"

class Projectile : public Character
{
public:
	Projectile();
	Projectile(glm::vec2 pPos2D, float r, int aimX, int aimY, GLuint tex);
	void update();

	bool hit;
	float angle;
};