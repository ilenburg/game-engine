#pragma once

#include "Character.h"

class Enemy : public Character
{
public:
	Enemy();
	Enemy(float px, float py);
	void update();

	bool aggro;
};