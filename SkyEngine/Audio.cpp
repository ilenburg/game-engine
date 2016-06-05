#include "Audio.h"

Audio::Audio()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
	backMusic = Mix_LoadMUS("Data/Audio/back.mp3");
	shoot = Mix_LoadWAV("Data/Audio/shoot.wav");
	enemyHurt = Mix_LoadWAV("Data/Audio/enemyHurt.wav");
	enemyDown = Mix_LoadWAV("Data/Audio/enemyDown.wav");
	injure = Mix_LoadWAV("Data/Audio/injure.wav");
	click = Mix_LoadWAV("Data/Audio/click.wav");
	Mix_VolumeMusic(90);
	Mix_VolumeChunk(shoot, 20);
	Mix_VolumeChunk(enemyHurt, 60);
	Mix_VolumeChunk(enemyDown, 60);
	Mix_VolumeChunk(click, 180);
	Mix_VolumeChunk(injure, 90);
	Mix_FadeInMusic(backMusic, -1, 5000);
}

Audio::~Audio()
{
	Mix_CloseAudio();
}

void Audio::play_shoot()
{
	Mix_PlayChannel( -1, shoot, 0 );
}

void Audio::play_eHurt()
{
	Mix_PlayChannel( -1, enemyHurt, 0 );
}

void Audio::play_eDown()
{
	Mix_PlayChannel( -1, enemyDown, 0 );
}

void Audio::play_injure()
{
	Mix_PlayChannel( -1, injure, 0 );
}

void Audio::play_click()
{
	Mix_PlayChannel( -1, click, 0 );
}