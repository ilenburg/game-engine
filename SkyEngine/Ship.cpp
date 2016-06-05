#include "Ship.h"

Ship::Ship()
{
	radius = 100;
	mass = 50;
	hp = 10;
	pos2D.x = 9815;
	pos2D.y = 100;
	vel2D = glm::vec2(0,0);
	acc2D = glm::vec2(0,20);
	float diameter = radius*2;
	glm::vec3 pos[4] = {
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(0.0f,diameter,0.0f),
		glm::vec3(diameter*2,0.0f,0.0f),
		glm::vec3(diameter*2,diameter,0.0f)};
	float graph_posX = pos2D.x - radius * 2;
	float graph_posY = pos2D.y - radius;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
	set_vao(pos);
}

void Ship::update()
{
	float graph_posX = pos2D.x - radius * 2;
	float graph_posY = pos2D.y - radius;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
}