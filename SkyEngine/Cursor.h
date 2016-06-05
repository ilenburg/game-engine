#pragma once

#include "Entity.h"

class Cursor : public Entity
{
public:
	Cursor();
	Cursor(int x, int y);

	void update(int nx, int ny, float bias);
	float radius;
	int x;
	int y;
	int xF;
	int yF;
};