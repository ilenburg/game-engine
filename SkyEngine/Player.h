#pragma once

#include "Character.h"

class Player : public Character
{
public:
	Player();
	void update();

	bool move_right;
	bool move_left;
	bool jump;
	bool ground;
	bool momentum;
	bool shoot;
	bool reload;
	bool inv;
	glm::mat4 camera;
};