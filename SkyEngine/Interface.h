#pragma once

#include <SDL.h>
#include "Resource.h"

class Interface
{
public:
	Interface();

	void update();

	Resource *objects;
	SDL_Event input;
};