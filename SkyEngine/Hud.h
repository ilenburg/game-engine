#pragma once

#include "Resource.h"
#include "Icon.h"
#include <vector>

class Hud
{
public:
	void update();
	void init();

	Resource *objects;
	std::vector<Icon> *lifeP;
	std::vector<Icon> *scoreP;
	int lifeCount;
	int scoreCount;
	int row;
	int column;
};