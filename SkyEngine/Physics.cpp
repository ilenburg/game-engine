#include "Physics.h"
#include "Calc.h"
#include <SDL.h>

Physics::Physics()
{
	gravity.x = 0;
	gravity.y = -1000;
	friction = 0.9f;
	inv_count = 0;
}

void Physics::init()
{
	int thisTime = SDL_GetTicks();
	deltaTime = (float)(thisTime - lastTime) / 1000;
	lastTime = thisTime;
}

void Physics::update()
{
	int thisTime = SDL_GetTicks();
	deltaTime = (float)(thisTime - lastTime) / 1000;
	lastTime = thisTime;
	if (objects->p1.inv) inv_count += deltaTime;
	if (inv_count >= 0.07) objects->p1.blink = false;
	if (inv_count >= 0.6)
	{
		 objects->p1.inv = false;
		 inv_count = 0;
	}

	if (objects->p1.shoot && !objects->p1.reload)
	{
		objects->sound.play_shoot();
		objects->p1.reload = true;
		int bias = 0;
		if (objects->p1.pos2D.x > 512)
		{
			bias = objects->p1.pos2D.x - 512;
			if (objects->p1.pos2D.x > 9512) bias = 9000;
		}
		float angle_adjust;
		objects->shoots.push_back(Projectile(objects->p1.pos2D, objects->p1.radius, objects->pointer.x, objects->pointer.y, objects->projeTex));
	}

	for (std::vector<Projectile>::iterator i = objects->shoots.begin(); i != objects->shoots.end();++i)
	{
		for (std::vector<Enemy>::iterator j = objects->enemies.begin(); j != objects->enemies.end();++j)
		{
			if(Calc::Collide(*i,*j))
			{
				Calc::CoResp(*i,*j);
				j->blink = true;
				i->hit = true;
				j->hp -= 1;
				if (j->hp > 0) objects->sound.play_eHurt();
			}
		}
	}


	for (std::vector<Enemy>::iterator j = objects->enemies.begin(); j != objects->enemies.end();)
	{
		if (j->hp <= 0)
		{
			objects->sound.play_eDown();
			j = objects->enemies.erase(j);
			objects->enemyDown += 1;
			objects->enemyCount -= 1;
		}
		else ++j;
	}
	for (std::vector<Projectile>::iterator i = objects->shoots.begin(); i != objects->shoots.end();)
	{
		 if (i->hit == true) i = objects->shoots.erase(i);
		 else ++i;
	}

	for (std::vector<Enemy>::iterator i = objects->enemies.begin(); i != objects->enemies.end();++i)
	{
		if(glm::distance(i->pos2D, objects->p1.pos2D) < 900 || i->hp < 10) i->aggro = true;
		if (i->aggro)
		{
			glm::vec2 dir = glm::normalize(objects->p1.pos2D - i->pos2D);
			dir = glm::vec2(dir.x*600,dir.y*600);
			i->acc2D = dir;
		}
		if(Calc::Collide(*i,objects->p1))
		{
			Calc::CoResp(*i,objects->p1);
			if (!objects->p1.inv)
			{
				objects->p1.hp -= 1;
				objects->sound.play_injure();
				objects->p1.inv = true;
				objects->p1.blink = true;
			}
		}
	}

	objects->p1.ground = false;
	for (std::vector<Foreground>::iterator j = objects->grounds.begin(); j != objects->grounds.end(); ++j)
	{
		if (Calc::Collide(objects->p1, *j))
		{
			if (!objects->p1.momentum && !objects->p1.jump) objects->p1.momentum = true;
			objects->p1.ground = true;
			if (gravity + glm::normalize(j->normal) * glm::length(gravity) != glm::vec2(0,0)) objects->p1.vel2D.y *= friction;
			else objects->p1.vel2D.y = 0;
		}
	}

	objects->update();

	glm::vec2 accel;
	if (objects->p1.ground) accel = objects->p1.acc2D + gravity + (glm::normalize(objects->grounds[0].normal) * glm::length(gravity));
	else accel = objects->p1.acc2D + gravity;
	if (objects->p1.ground)
	{
		if((!objects->p1.move_right && !objects->p1.move_left) || (objects->p1.move_right && objects->p1.move_left)
			|| objects->p1.vel2D.x > 300 || objects->p1.vel2D.x < -300)
		{
		}
		if (objects->p1.vel2D.x > 10  || objects->p1.vel2D.x < -10) objects->p1.vel2D.x *= friction;
		else objects->p1.vel2D.x = 0;
	}

	for (std::vector<Projectile>::iterator j = objects->shoots.begin(); j != objects->shoots.end(); ++j)
	{
		j->pos2D = Calc::Euler(j->pos2D,j->vel2D,j->acc2D,deltaTime);
		j->vel2D = Calc::Vel(j->vel2D,j->acc2D,deltaTime);
		j->acc2D = glm::vec2(0,0);
	}

	for (std::vector<Enemy>::iterator i = objects->enemies.begin(); i != objects->enemies.end(); ++i)
	{
		i->pos2D = Calc::Euler(i->pos2D,i->vel2D,i->acc2D,deltaTime);
		i->vel2D = Calc::Vel(i->vel2D,i->acc2D,deltaTime);
		i->acc2D = glm::vec2(0,0);
	}

	if(objects->s1.vel2D.y > 30) objects->s1.acc2D = glm::vec2(0,-30);
	if(objects->s1.vel2D.y < -30) objects->s1.acc2D = glm::vec2(0,30);

	objects->p1.pos2D = Calc::Euler(objects->p1.pos2D,objects->p1.vel2D,accel,deltaTime);
	objects->p1.vel2D = Calc::Vel(objects->p1.vel2D,accel,deltaTime);

	objects->s1.pos2D = Calc::Euler(objects->s1.pos2D,objects->s1.vel2D,objects->s1.acc2D,deltaTime);
	objects->s1.vel2D = Calc::Vel(objects->s1.vel2D,objects->s1.acc2D,deltaTime);
}