#include "Background.h"


Background::Background()
{
	size_x = 10024;
	size_y = 768;
	glm::vec3 pos[4] = {
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(0.0f,size_y,0.0f),
		glm::vec3(size_x,0.0f,0.0f),
		glm::vec3(size_x,size_y,0.0f)};
	set_vao(pos, 10);
}

Background::Background(int screen_width, int screen_height)
{
	glm::vec3 pos[4] = {
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(0.0f,(float)screen_height,0.0f),
		glm::vec3((float)screen_width,0.0f,0.0f),
		glm::vec3((float)screen_width,(float)screen_height,0.0f)};
	set_vao(pos);
}