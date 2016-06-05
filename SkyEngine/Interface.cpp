#include "Interface.h"

Interface::Interface()
{
	SDL_ShowCursor(0);
}

void Interface::update()
{
	int x, y;
	float bias = 0;
	SDL_GetMouseState(&x,&y);
	y = -y+768;
	if (objects->p1.pos2D.x > 512)
	{
		bias = objects->p1.pos2D.x - 512;
		if (objects->p1.pos2D.x > 9512) bias = 9000;
	}
	x +=bias;
	objects->pointer.update(x,y,bias);
	while (SDL_PollEvent(&input))
	{
		if (!(objects->pause))
		{
			switch(input.type)
			{
				case SDL_KEYDOWN:
					if (input.key.keysym.sym == SDLK_d || input.key.keysym.sym == SDLK_RIGHT)
					{
						objects->p1.move_right = true;
					}
					if (input.key.keysym.sym == SDLK_a || input.key.keysym.sym == SDLK_LEFT)
					{
						objects->p1.move_left = true;
					}
					if (input.key.keysym.sym == SDLK_w || input.key.keysym.sym == SDLK_SPACE || input.key.keysym.sym == SDLK_UP)
					{
						objects->p1.jump = true;
					}
					break;
				case SDL_KEYUP:
					if (input.key.keysym.sym == SDLK_d || input.key.keysym.sym == SDLK_RIGHT)
					{
						objects->p1.move_right = false;
					}
					if (input.key.keysym.sym == SDLK_a || input.key.keysym.sym == SDLK_LEFT)
					{
						objects->p1.move_left = false;
					}
					if (input.key.keysym.sym == SDLK_w || input.key.keysym.sym == SDLK_SPACE || input.key.keysym.sym == SDLK_UP)
					{
						objects->p1.jump = false;
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (input.button.button == SDL_BUTTON_LEFT)
					{
						objects->p1.shoot = true;
					}
					break;
				case SDL_MOUSEBUTTONUP:
					if (input.button.button == SDL_BUTTON_LEFT)
					{
						objects->p1.shoot = false;
						objects->p1.reload = false;
					}
					break;
				default:
					break;
			}
		}
		else
		{
			switch(input.type)
			{
				case SDL_MOUSEBUTTONDOWN:
					if (input.button.button == SDL_BUTTON_LEFT)
					{
						if (glm::distance(glm::vec2(objects->pointer.xF,objects->pointer.yF),objects->play.pos2D) 
						< (objects->play.radius + objects->play.radius/2))
						{
							objects->sound.play_eDown();
							objects->start = true;
						}
						else if (glm::distance(glm::vec2(objects->pointer.xF,objects->pointer.yF),objects->quit.pos2D)
						< (objects->quit.radius + objects->quit.radius/2))
						{
							objects->game_on = false;
						}
						else objects->sound.play_click();
					}
					break;
				default:
					break;
			}
		}
	}
}

