#pragma once

#include <sstream>
#include "Resource.h"
#include "Graphics.h"

class Renderer
{
public:
	Renderer();
	void draw(Entity ent);
	void update();
	void get_fps();

	Resource *objects;
	int numFrames;
	int lastTime;

private:
	Graphics view;
};