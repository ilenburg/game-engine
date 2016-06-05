#include "Entity.h"

Entity::Entity()
{
	vao = 0;
	texture = 0;
	modelMatrix = glm::mat4();
	fixed = false;
	blink = false;
	player = false;
	hp = 20;
}

void Entity::set_vao(glm::vec3 pos[4], int texRepeatX, int texRepeatY)
{
	glm::vec2 tex[4] = {
		glm::vec2(0,texRepeatY),
		glm::vec2(0,0),
		glm::vec2(texRepeatX,texRepeatY),
		glm::vec2(texRepeatX,0)};

	glm::vec4 colour[4] = {
		glm::vec4(-1,0,0,1),
		glm::vec4(-1,0,0,1),
		glm::vec4(-1,0,0,1),
		glm::vec4(-1,0,0,1)};

	GLuint posVBO;
	GLuint texVBO;
	GLuint colourVBO;

	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);

	glGenBuffers(1, &posVBO);
	glBindBuffer(GL_ARRAY_BUFFER, posVBO);

	glBufferData(GL_ARRAY_BUFFER, 4* sizeof(glm::vec3),pos,GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &colourVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colourVBO);

	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(glm::vec4), colour, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &texVBO);
	glBindBuffer(GL_ARRAY_BUFFER, texVBO);

	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(glm::vec3), tex, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}

void Entity::update()
{
}