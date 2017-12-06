/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description:
*/
#ifndef HEADER_H
#define HEADER_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using std::cout;
using std::endl;




class Player: public sf::RectangleShape {
public:
	Player(sf::Color const &newColor, sf::Vector2f const &size, sf::Vector2f const &pos);

private:

};

class Projectile: public sf::CircleShape {
public:
	Projectile(const sf::Color & color, const float & radius, const sf::Vector2f & position);
	void Load(const sf::Color & color, const float & radius, const sf::Vector2f & position);
	void Destroy();


private:

};

class Game {
public:
	Game();
	void runGame();
	void moveProjectiles(Projectile &projectile1, Projectile &projectile2, Projectile &projectile3, Projectile &projectile4, Projectile &projectile5, Projectile &projectile6, Projectile &projectile7, Projectile &projectile8, Projectile &projectile9, Projectile &projectile10);
	void checkProjectiles(Projectile &projectile1, Projectile &projectile2, Projectile &projectile3, Projectile &projectile4, Projectile &projectile5, Projectile &projectile6, Projectile &projectile7, Projectile &projectile8, Projectile &projectile9, Projectile &projectile10);
};
#endif