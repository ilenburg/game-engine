#include "Menu.h"

void Menu::init()
{
	playP = &(objects->play);
	quitP = &(objects->quit);

	*playP = Icon(325,150,50,2);
	*quitP = Icon(675,150,50,2);

	playP->texture = objects->playTex;
	quitP->texture = objects->quiTex;

	showP = &(objects->show);

	*showP = Icon(500,500,150);

	showP->texture = objects->logoTex;
}