#pragma once

#include "Enemy.h"
#include "Background.h"
#include "Foreground.h"
#include "Player.h"
#include "Audio.h"
#include "Projectile.h"
#include "Cursor.h"
#include "Icon.h"
#include "Ship.h"
#include <vector>

class Resource
{
public:
	Resource();
	void init();
	void load_tex();
	void load_enemies();
	void load_ground();
	void load_hud();
	void update();
	
	GLuint playerTex;
	GLuint enemyTex;
	GLuint foreTex;
	GLuint backTex;
	GLuint projeTex;
	GLuint poinTex;
	GLuint lifeTex;
	GLuint scoreTex;
	GLuint shipTex;
	GLuint playTex;
	GLuint quiTex;
	GLuint winTex;
	GLuint loseTex;
	GLuint logoTex;

	Background backG;
	Audio sound;
	Player p1;
	Cursor pointer;
	Ship s1;
	std::vector<Foreground> grounds;
	std::vector<Enemy> enemies;
	std::vector<Projectile> shoots;
	std::vector<Icon> life;
	std::vector<Icon> score;
	Icon play;
	Icon quit;
	Icon show;
	int enemyCount;
	int enemyDown;
	bool game_on;
	bool pause;
	bool start;
};