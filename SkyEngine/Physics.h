#pragma once

#include "Resource.h"

class Physics
{
public:
	Physics();
	void update();
	void init();

	Resource *objects;
	glm::vec2 gravity;
	int lastTime;
	float deltaTime;
	float friction;
	float inv_count;
};