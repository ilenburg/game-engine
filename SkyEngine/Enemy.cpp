#include "Enemy.h"

Enemy::Enemy()
{
	radius = 100;
	mass = 50;
	hp = 10;
	pos2D.x = 300;
	pos2D.y = 300;
	acc2D = glm::vec2(0,0);
	vel2D = glm::vec2(-90,0);
	aggro = false;
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

Enemy::Enemy(float px, float py)
{
	radius = 100;
	mass = 50;
	hp = 10;
	pos2D.x = px;
	pos2D.y = py;
	acc2D = glm::vec2(0,0);
	vel2D = glm::vec2(-150,0);
	aggro = false;
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

void Enemy::update()
{
	float graph_posX = pos2D.x - radius;
	float graph_posY = pos2D.y - radius;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
}