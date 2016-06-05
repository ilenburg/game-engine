#include "Foreground.h"


Foreground::Foreground()
{
	p1.x = 0;
	p1.y = 100;
	p2.x = 10024;
	p2.y = 100;
	p3.x = 0;
	p3.y = 0;
	p4.x = 10024;
	p4.y = 0;
	normal = glm::vec2(-1*(p2 - p1).y, (p2 - p1).x);
	glm::vec3 pos[4] = {
		glm::vec3(p3,0.0f),
		glm::vec3(p1,0.0f),
		glm::vec3(p4,0.0f),
		glm::vec3(p2,0.0f)};
	set_vao(pos, ((p2.x-p1.x)*40)/10024);
}

Foreground::Foreground(int p1X, int p1Y, int p4X, int p4Y)
{
	p1.x = p1X;
	p1.y = p1Y;
	p2.x = p4X;
	p2.y = p1Y;
	p3.x = p1X;
	p3.y = p4Y;
	p4.x = p4X;
	p4.y = p4Y;
	normal = glm::vec2(-1*(p2 - p1).y, (p2 - p1).x);
	glm::vec3 pos[4] = {
		glm::vec3(p3,0.0f),
		glm::vec3(p1,0.0f),
		glm::vec3(p4,0.0f),
		glm::vec3(p2,0.0f)};
	set_vao(pos, ((p2.x-p1.x)*40)/10024);
}