#include "Projectile.h"

Projectile::Projectile()
{
	hit = false;
}

float calc_angle(glm::vec2 x, glm::vec2 y)
{
	float theta = glm::dot(x,y) / (glm::length(x) * glm::length(y));
	return glm::acos(theta);
}

Projectile::Projectile(glm::vec2 pPos2D, float r, int aimX, int aimY, GLuint tex)
{
	glm::vec2 target = glm::vec2(aimX,aimY);
	glm::vec2 path = target - pPos2D;
	glm::vec2 norm = glm::normalize(path);
	pos2D = pPos2D;
	vel2D = glm::vec2(norm.x*1200,norm.y*1200);
	angle = calc_angle(path,glm::vec2(1,0)) * 57.29f;
	if (path.y < 0) angle = -angle;
	radius = 15;
	mass = 5;
	float diameter = radius*2;
	glm::vec3 pos[4] = {
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(0.0f,diameter,0.0f),
		glm::vec3(diameter*2,0.0f,0.0f),
		glm::vec3(diameter*2,diameter,0.0f)};
	float graph_posX = pos2D.x - radius;
	float graph_posY = pos2D.y - radius;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
	texture = tex;
	set_vao(pos);
}

void Projectile::update()
{
	float graph_posX = pos2D.x;
	float graph_posY = pos2D.y;
	modelMatrix = glm::translate(glm::mat4(),glm::vec3(graph_posX, graph_posY,0.0f));
	modelMatrix = glm::rotate(modelMatrix,angle,glm::vec3(0,0,1));
	modelMatrix = glm::translate(modelMatrix,glm::vec3(-radius, -radius,0.0f));
}