#include "Renderer.h"
#include "Interface.h"
#include "Physics.h"
#include "Hud.h"
#include "Menu.h"

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Renderer scene;
	Interface input;
	Physics logic;
	Hud hud;
	Menu menu;
	Resource *init_obj;
	init_obj = new Resource;
	hud.objects = init_obj;
	scene.objects = init_obj;
	input.objects = init_obj;
	logic.objects = init_obj;
	menu.objects = init_obj;
	menu.init();
	while(init_obj->game_on){
		if (init_obj->pause) 
		{
			scene.update();
			input.update();
			if (init_obj->start)
			{
				delete init_obj;
				init_obj = new Resource;
				init_obj->init();
				menu.init();
				hud.init();
				logic.init();
				init_obj->pause = false;
				init_obj->start = false;
			}
		}
		else{
			scene.update();
			input.update();
			hud.update();
			logic.update();
		}
	}
	delete init_obj;
	SDL_Quit;

	return 0;
}