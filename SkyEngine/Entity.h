#pragma once

#include <gl\glew.h>
#include <glm\gtc\matrix_transform.hpp>

class Entity
{
public:
	Entity();
	void set_vao(glm::vec3 pos[4], int texRepeatX = 1, int texRepeatY = 1);
	virtual void update();

	GLuint vao;
	GLuint texture;
	glm::mat4 modelMatrix;
	bool blink;
	bool fixed;
	bool player;
	int hp;
};