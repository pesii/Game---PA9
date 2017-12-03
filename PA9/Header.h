#pragma once

#include "standard_dependency.h"
#include <SFML/Graphics.hpp>

/* Will be rolling out macros. We want to minimize macro use and for the sake of portability and generic-ness
 * we will have the following macros be defined as private members of their rightful classes.
 */
#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 900
#define PLAYER_WIDTH 30
#define PLAYER_HEIGHT 20
#define ENEMY_WIDTH 30
#define ENEMY_HEIGHT 20
#define ENEMY_SPEED 0.0125
#define ORIGIN 0


class SpawnObject : public sf::RectangleShape {
public:
	SpawnObject(sf::Color const &newColor, sf::Vector2f const &size, sf::Vector2f const &position)
	{
		cout << "Inside SpawnObject constructor!" << endl;

		setFillColor(newColor);
		setSize(size);
		setPosition(position);
	}

	void setObjWidth(float new_width) {
		obj_width = new_width;
	}
	void setObjHeight(float new_height) {
		obj_height = new_height;
	}
protected:

	float obj_width;
	float obj_height;
};


class Player: public SpawnObject {
public:
	//create_player(sf::Color const &newColor, float )
	Player(sf::Color const &newColor, sf::Vector2f const &size, sf::Vector2f const &pos)
		: SpawnObject(newColor, size, pos) {
		cout << "Inside player constructor!" << endl;
	}

	void setPlayerWidth(float new_width) { 
		
	}

};

class Enemy : public SpawnObject {
public:
	Enemy(sf::Color const &newColor, sf::Vector2f const &size, sf::Vector2f const &pos)
		: SpawnObject(newColor, size, pos) {
		cout << "Inside player constructor!" << endl;
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

class Projectile: public sf::CircleShape {
public:
	Projectile();
	Projectile(const sf::Color &color, const float &radius, const sf::Vector2f &position);


private:

};

class Game {
public:
	Game();
	void runGame();
	void moveProjectiles(vector<Projectile*> &projectiles);

};