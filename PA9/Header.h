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

class sf::Sprite: public sf::CircleShape {
public:
	sf::Sprite(const sf::Color & color, const float & radius, const sf::Vector2f & position);
	void Load(const sf::Color & color, const float & radius, const sf::Vector2f & position);
	void Destroy();


private:

};

class Game {
public:
	Game();
	void runGame();
	void moveProjectiles(sf::Sprite &projectile1, sf::Sprite &projectile2, sf::Sprite &projectile3, sf::Sprite &projectile4, sf::Sprite &projectile5, sf::Sprite &projectile6, sf::Sprite &projectile7, sf::Sprite &projectile8, sf::Sprite &projectile9, sf::Sprite &projectile10);
	void checkProjectiles(sf::Sprite &projectile1, sf::Sprite &projectile2, sf::Sprite &projectile3, sf::Sprite &projectile4, sf::Sprite &projectile5, sf::Sprite &projectile6, sf::Sprite &projectile7, sf::Sprite &projectile8, sf::Sprite &projectile9, sf::Sprite &projectile10);
};
#endif