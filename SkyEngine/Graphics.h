#pragma once

#include<SDL.h>
#include <gl\glew.h>
#include <string>
#include <fstream>
#include <glm\gtc\matrix_transform.hpp>

class Graphics
{
public:
	Graphics();
	~Graphics();
	void init();
	void set_shaders();

	SDL_Window* window;
	SDL_GLContext glContext;
	GLint shaderModelMat;
	GLint shaderViewMat;
	GLint isPlayer;
	GLint colourON;
	GLint colourVar;
	GLint pFixed;
	int  screen_width;
	int  screen_height;
};