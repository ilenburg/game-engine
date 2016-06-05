#pragma once

#include "Entity.h"

class Background : public Entity
{
public:
	Background();
	Background(int screen_width, int screen_height);

	float size_x;
	float size_y;
};