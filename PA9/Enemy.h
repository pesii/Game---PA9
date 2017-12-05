#pragma once

#include "SpawnObjects.h"

class Enemy : public SpawnObject {
public:
	Enemy(sf::Color const &newColor = sf::Color::Red, 
      sf::Vector2f const &size = sf::Vector2f(30, 30), 
      sf::Vector2f const &pos = sf::Vector2f(SCREEN_HEIGHT / 2, SCREEN_HEIGHT / 2))
		: SpawnObject(newColor, size, pos) {
		cout << "Inside player constructor!" << endl;
	}
	/*
	void setColor(sf::Color const &new_color) {
		setFillColor(new_color);
	}
	*/
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