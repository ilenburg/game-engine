#include "Resource.h"
#include <SOIL.h>

Resource::Resource()
{
	game_on = true;
	pause = true;
	start = false;
	load_tex();
	load_ground();
}

void Resource::init()
{
	load_hud();
	load_enemies();
}

void Resource::load_hud()
{
	int x = 50;
	int y = 718;
	int size = 25;

	for(int i = 0; i < p1.hp; ++i)
	{
		life.push_back(Icon(x,y,size));
		x += 50;
	}

	for (std::vector<Icon>::iterator i = life.begin(); i != life.end(); ++i) i->texture = lifeTex;
}

void Resource::load_ground()
{
	grounds.push_back(Foreground(-100,2000,0,0));
	grounds.push_back(Foreground(10024,2000,10124,0));
	int y1 = 100;
	int y2 = 0;
	grounds.push_back(Foreground(0,y1,2000,y2));
	grounds.push_back(Foreground(2300,y1,5000,y2));
	grounds.push_back(Foreground(5200,y1+100,5500,y2+100));
	grounds.push_back(Foreground(5800,y1+100,6500,y2+100));
	grounds.push_back(Foreground(6800,y1+100,8000,y2+100));
	grounds.push_back(Foreground(8300,y1,9600,y2));

	for (std::vector<Foreground>::iterator i = grounds.begin(); i != grounds.end(); ++i) i->texture = foreTex;
}

void Resource::load_enemies()
{

	enemyCount = 28;
	enemyDown = 0;

	enemies.push_back(Enemy(1300, 600));
	enemies.push_back(Enemy(1900, 200));
	enemies.push_back(Enemy(2600, 500));
	enemies.push_back(Enemy(3300, 400));
	enemies.push_back(Enemy(4000, 800));
	enemies.push_back(Enemy(4700, 300));
	enemies.push_back(Enemy(5400, 500));
	enemies.push_back(Enemy(5900, 200));
	enemies.push_back(Enemy(6500, 700));
	enemies.push_back(Enemy(7200, 500));

	enemies.push_back(Enemy(8000, 600));
	enemies.push_back(Enemy(8800, 300));
	enemies.push_back(Enemy(9700, 800));
	enemies.push_back(Enemy(10300, 600));
	enemies.push_back(Enemy(11600, 500));
	enemies.push_back(Enemy(12300, 400));
	enemies.push_back(Enemy(13700, 300));
	enemies.push_back(Enemy(14500, 700));
	enemies.push_back(Enemy(15300, 200));
	enemies.push_back(Enemy(16200, 500));

	enemies.push_back(Enemy(17000, 600));
	enemies.push_back(Enemy(17600, 300));
	enemies.push_back(Enemy(18400, 500));
	enemies.push_back(Enemy(19600, 800));
	enemies.push_back(Enemy(21500, 300));
	enemies.push_back(Enemy(23000, 600));
	enemies.push_back(Enemy(23100, 400));
	enemies.push_back(Enemy(23200, 200));

	for (std::vector<Enemy>::iterator i = enemies.begin(); i != enemies.end(); ++i) i->texture = enemyTex;
}

void texLoader(GLuint &tex, const char *name)
{
	int width;
	int height;
	int channels;

	unsigned char *texData = SOIL_load_image(name,&width,&height,&channels,0);

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	glTexImage2D(GL_TEXTURE_2D, 0, channels == 4 ? GL_RGBA8 : GL_RGB8, width, height, 0, channels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, texData);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Resource::load_tex()
{

	texLoader(playerTex, "Data/Textures/player.jpg");
	texLoader(enemyTex, "Data/Textures/enemy.jpg");
	texLoader(backTex, "Data/Textures/background.jpg");
	texLoader(foreTex, "Data/Textures/foreground.jpg");
	texLoader(projeTex, "Data/Textures/projectile.jpg");
	texLoader(poinTex, "Data/Textures/cursor.jpg");
	texLoader(lifeTex, "Data/Textures/life.jpg");
	texLoader(scoreTex, "Data/Textures/score.jpg");
	texLoader(shipTex, "Data/Textures/ship.jpg");
	texLoader(playTex, "Data/Textures/play.jpg");
	texLoader(quiTex, "Data/Textures/quit.jpg");
	texLoader(winTex, "Data/Textures/win.jpg");
	texLoader(loseTex, "Data/Textures/lose.jpg");
	texLoader(logoTex, "Data/Textures/logo.jpg");

	p1.texture = playerTex;
	backG.texture = backTex;
	pointer.texture = poinTex;
	s1.texture = shipTex;
}

void Resource::update()
{
	p1.update();
	s1.update();
	for (std::vector<Projectile>::iterator j = shoots.begin(); j != shoots.end();)
	{
		 j->update();
		 if(glm::distance(p1.pos2D,j->pos2D ) > 900) j = (shoots.erase(j));
		 else ++j;
	}
	for (std::vector<Enemy>::iterator i = enemies.begin(); i != enemies.end(); ++i) i->update();
	if (p1.pos2D.y < -100) p1.hp -= 1;
	if (glm::distance(p1.pos2D,s1.pos2D) < s1.radius * 2)
	{
		show = Icon(500,500,150,2);
		show.texture= winTex;
		pause = true;
	}
	else if (life.empty())
	{
		show = Icon(500,500,150,2);
		show.texture= loseTex;
		pause = true;
	}
}