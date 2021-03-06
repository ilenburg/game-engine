#include "Player.h"

Player::Player()
{
	move_right = false;
	move_left = false;
	jump = false;
	ground = false;
	momentum = true;
	shoot = false;
	reload = false;
	inv = false;
	player = true;
	hp = 6;
	radius = 50;
	mass = 100;
	pos2D.x = 150;
	pos2D.y = 150;
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

void Player::update()
{
	acc2D = glm::vec2(0,0);
	if (jump && ground && momentum)
	{
		ground = false;
		momentum = false;
		acc2D.y += 30000;
		if (move_right && vel2D.x < 300) acc2D.x += 900;
		if (move_left && vel2D.x > -300) acc2D.x -= 900;
	}
	else
	{
		if (move_right && vel2D.x < 300) acc2D.x += 900;
		if (move_left && vel2D.x > -300) acc2D.x -= 900;
	}

	float graph_posX = pos2D.x - radius;
	float graph_posY = pos2D.y - radius;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
	if (pos2D.x > 512 && pos2D.x < 9512) camera = glm::translate(glm::mat4(),glm::vec3(-1*pos2D.x+512, 0,0.0f));
}