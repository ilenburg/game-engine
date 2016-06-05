#include "Hud.h"

void Hud::init()
{
	row = 986.5;
	column = 730.5;
	lifeP = &(objects->life);
	scoreP = &(objects->score);
	lifeCount = objects->p1.hp;
	scoreCount = objects->enemyDown;
}

void Hud::update()
{
	while (lifeCount > objects->p1.hp && lifeCount > 0)
	{
		lifeP->pop_back();
		lifeCount -= 1;
	}
	while (scoreCount < objects->enemyDown)
	{
		Icon entry = Icon(row,column,12.5);
		entry.texture = objects->scoreTex;
		scoreP->push_back(entry);

		scoreCount += 1;
		row -= 25;
		if (row <= 686.5)
		{
			row = 986.5;
			column -= 25;
		}
	}
}