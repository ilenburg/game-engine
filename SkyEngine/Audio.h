#pragma once

#include <SDL_mixer.h>

class Audio
{
public:
	Audio();
	~Audio();
	void play_shoot();
	void play_eHurt();
	void play_hit();
	void play_eDown();
	void play_injure();
	void play_click();

	Mix_Music *backMusic;
	Mix_Chunk *shoot;
	Mix_Chunk *enemyHurt;
	Mix_Chunk *enemyDown;
	Mix_Chunk *injure;
	Mix_Chunk *click;
};