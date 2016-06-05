#pragma once

#include "Character.h"
#include "Foreground.h"

class Calc
{
public:
	static glm::vec2 Vel(glm::vec2 u, glm::vec2 a, float t);
	static glm::vec2 Euler(glm::vec2 s, glm::vec2 u, glm::vec2 a, float t);
	static bool Collide(Character &c1, Character c2);
	static bool Collide(Character &c, Foreground f);
	static bool CollideSides(Character &c, Foreground f);
	static void CoResp(Character &c1, Character &c2);
};