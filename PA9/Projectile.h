/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description:
*/
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "SpawnObjects.h"

class Projectile: public sf::CircleShape {
public:
	Projectile();
	Projectile(const sf::Color &color, const float &radius, const sf::Vector2f &position);


private:

};

#endif