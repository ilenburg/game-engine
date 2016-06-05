#include "Renderer.h"

Renderer::Renderer()
{
	numFrames = 0;
	lastTime = SDL_GetTicks();
}

void Renderer::update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glUniformMatrix4fv(view.shaderViewMat, 1, GL_FALSE,(float*)&objects->p1.camera);
	draw(objects->backG);
	for (std::vector<Foreground>::iterator j = objects->grounds.begin(); j != objects->grounds.end(); ++j) draw(*j);
	draw(objects->p1);
	draw(objects->s1);
	for (std::vector<Projectile>::iterator j = objects->shoots.begin(); j != objects->shoots.end(); ++j) draw(*j);
	for (std::vector<Enemy>::iterator i = objects->enemies.begin(); i != objects->enemies.end(); ++i) draw(*i);
	if (objects->pause) draw(objects->show);
	if (objects->pause) draw(objects->play);
	if (objects->pause) draw(objects->quit);
	draw(objects->pointer);
	for (std::vector<Icon>::iterator i = objects->score.begin(); i != objects->score.end(); ++i) draw(*i);
	for (std::vector<Icon>::iterator i = objects->life.begin(); i != objects->life.end(); ++i) draw(*i);
	SDL_GL_SwapWindow(view.window);
	get_fps();
}

void Renderer::draw(Entity ent)
{
	glBindVertexArray(ent.vao);
	glBindTexture(GL_TEXTURE_2D, ent.texture);
	glUniformMatrix4fv(view.shaderModelMat, 1, GL_FALSE,(float*)&ent.modelMatrix);
	glUniform1f(view.colourON, ent.blink);
	glUniform1f(view.isPlayer, ent.player);
	glUniform1f(view.pFixed, ent.fixed);
	glUniform1f(view.colourVar, (float)ent.hp/10.0f);
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Renderer::get_fps()
{
	++numFrames;
	if ((SDL_GetTicks() - lastTime) >= 1000)
	{
		std::stringstream name;
		lastTime = SDL_GetTicks();
		name << "SkyEngine - FPS: " << numFrames;
		SDL_SetWindowTitle(view.window, name.str().c_str());
		numFrames = 0;
	}
}