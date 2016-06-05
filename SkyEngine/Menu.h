#pragma once

#include "Resource.h"
#include "Icon.h"

class Menu
{
public:
	void init();

	Resource *objects;
	Icon *playP;
	Icon *quitP;
	Icon *showP;
};