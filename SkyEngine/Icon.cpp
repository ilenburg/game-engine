#include "Icon.h"

Icon::Icon()
{
	radius = 12.5;
	fixed = true;
	pos2D = glm::vec2(50,700);
	float diameter = radius*2;
	glm::vec3 pos[4] = {
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(0.0f,diameter,0.0f),
		glm::vec3(diameter,0.0f,0.0f),
		glm::vec3(diameter,diameter,0.0f)};
	float graph_posX = pos2D.x - radius;
	float graph_posY = pos2D.y - radius;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
	set_vao(pos);
}

Icon::Icon(int x, int y, float size)
{
	radius = size;
	fixed = true;
	pos2D = glm::vec2(x,y);
	float diameter = radius*2;
	glm::vec3 pos[4] = {
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(0.0f,diameter,0.0f),
		glm::vec3(diameter,0.0f,0.0f),
		glm::vec3(diameter,diameter,0.0f)};
	float graph_posX = pos2D.x - radius;
	float graph_posY = pos2D.y - radius;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
	set_vao(pos);
}

Icon::Icon(int x, int y, float size, int sVar)
{
	radius = size;
	fixed = true;
	pos2D = glm::vec2(x,y);
	float diameter = radius*2;
	glm::vec3 pos[4] = {
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(0.0f,diameter,0.0f),
		glm::vec3(diameter*sVar,0.0f,0.0f),
		glm::vec3(diameter*sVar,diameter,0.0f)};
	float graph_posX = pos2D.x - radius*sVar;
	float graph_posY = pos2D.y - radius;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
	set_vao(pos);
}