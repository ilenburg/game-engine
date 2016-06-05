#include "Cursor.h"

Cursor::Cursor()
{
	radius = 20;
	x = 512;
	y = 384;
	fixed = true;
	float diameter = radius*2;
	glm::vec3 pos[4] = {
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(0.0f,diameter,0.0f),
		glm::vec3(diameter,0.0f,0.0f),
		glm::vec3(diameter,diameter,0.0f)};
	float graph_posX = x - radius;
	float graph_posY = y - radius;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
	set_vao(pos);
}

Cursor::Cursor(int x, int y)
{
	radius = 25;
	x = x;
	y = y;
	fixed = true;
	float diameter = radius*2;
	glm::vec3 pos[4] = {
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(0.0f,diameter,0.0f),
		glm::vec3(diameter,0.0f,0.0f),
		glm::vec3(diameter,diameter,0.0f)};
	float graph_posX = x - radius;
	float graph_posY = y - radius;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
	set_vao(pos);
}

void Cursor::update(int nx, int ny, float bias)
{
	x = nx;
	y = ny;
	xF = x - bias;
	yF = y;
	float graph_posX = xF - radius;
	float graph_posY = yF - radius;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
}