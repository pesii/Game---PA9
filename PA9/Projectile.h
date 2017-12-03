#pragma once

#include "SpawnObjects.h"

class Projectile: public sf::CircleShape {
public:
	Projectile();
	Projectile(const sf::Color &color, const float &radius, const sf::Vector2f &position);


private:

};