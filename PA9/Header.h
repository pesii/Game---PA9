#pragma once

#include "standard_dependency.h"
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 900
#define PLAYER_WIDTH 30
#define PLAYER_HEIGHT 20
#define ENEMY_WIDTH 30
#define ENEMY_HEIGHT 20
#define ENEMY_SPEED 0.125



class Player: public sf::RectangleShape {
public:
	Player(sf::Color const &newColor, sf::Vector2f const &size, sf::Vector2f const &pos);

private:

};

class Projectile: public sf::CircleShape {
public:
	Projectile();
	Projectile(const sf::Color & color, const float & radius, const sf::Vector2f & position);


private:

};

class Enemies : public sf::RectangleShape {
public:
	Enemies(sf::Color const &newColor, sf::Vector2f const &size, sf::Vector2f const &pos)
	{
		this->setFillColor(newColor);
		this->setSize(size);
		this->setPosition(pos);
	}

	void setColor(sf::Color const &new_color) {
		setFillColor(new_color);
	}
	/*
	void setSize(string size) {
		setSize(size);
	}
	*/

	/*
	Enemies Spawn(sf::Color const enemy_color, double enemy_size_x, double enemy_size_y,
		double enemy_coord_x, double enemy_coord_y);
		*/
};

class Game {
public:
	Game();
	void runGame();
	void moveProjectiles(vector<Projectile*> &projectiles);

};