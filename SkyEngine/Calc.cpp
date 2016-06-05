#include "Calc.h"

glm::vec2 Calc::Vel(glm::vec2 u, glm::vec2 a, float t)
{
	return (u + a*t);
}

glm::vec2 Calc::Euler(glm::vec2 s, glm::vec2 u, glm::vec2 a, float t)
{
	glm::vec2 v1 = Vel(u, a, t);
	glm::vec2 c1 = Vel(s, v1, t);
	return c1;
}

bool Calc::Collide(Character &c1, Character c2)
{
	float x = pow(c2.pos2D.x - c1.pos2D.x,2.0f);
	float y = pow(c2.pos2D.y - c1.pos2D.y,2.0f);
	float dist = sqrt(x+y);

	float p = c1.radius + c2.radius - dist;
	glm::vec2 n = glm::normalize(c1.pos2D - c2.pos2D);
	glm::vec2 offset = n * p;

	if (dist < (c1.radius + c2.radius)) 
	{
		c1.pos2D+=offset;
		return true;
	}
	else return false;
}

bool collisionTest(Character &c, glm::vec2 p1, glm::vec2 p2)
{
	glm::vec2 closest;
	glm::vec2 seg_v = p2 - p1;
	glm::vec2 pt_v = c.pos2D - p1;
	float proj_mag = glm::dot(pt_v, glm::normalize(seg_v));
	glm::vec2 proj_v = glm::normalize(seg_v) * proj_mag;
	if (proj_mag < 0) closest = p1;
	else if (proj_mag > glm::length(seg_v)) closest = p2;
	else closest = p1 + proj_v;
	glm::vec2 dist_v = c.pos2D - closest;
	glm::vec2 offset = (c.radius - glm::length(dist_v)) * glm::normalize(dist_v);
	if (abs(glm::length(dist_v)) < c.radius)
	{
		c.pos2D+=offset;
		return true;
	}
	else return false;
}

bool Calc::Collide(Character &c, Foreground f)
{
	if (collisionTest(c, f.p3, f.p1));
	if (collisionTest(c, f.p2, f.p4));
	if (collisionTest(c, f.p4, f.p3));
	return collisionTest(c, f.p1, f.p2);
}

bool Calc::CollideSides(Character &c, Foreground f)
{
	if(collisionTest(c, f.p4, f.p1))
	return true;
	else return false;
}

void Calc::CoResp(Character &c1, Character &c2)
{
	glm::vec2 n = glm::normalize(c1.pos2D - c2.pos2D);
	float vn = glm::dot(n,(c1.vel2D - c2.vel2D));
	float eq1 = (-1*(1+0.9))*vn;
	float mass = (1/c1.mass + 1/c2.mass);
	float eq2 = glm::dot(n,(n*(mass)));
	float j = eq1/eq2;
	glm::vec2 v1 = c1.vel2D + n*(j/c1.mass);
	glm::vec2 v2 = c2.vel2D - n*(j/c2.mass);
	c1.vel2D = v1;
	c2.vel2D = v2;
}