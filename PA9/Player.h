#pragma once

#include "SpawnObjects.h"

class Player: public SpawnObject {
public:
	//create_player(sf::Color const &newColor, float )
	Player(sf::Color const &newColor, sf::Vector2f const &size, sf::Vector2f const &pos)
		: SpawnObject(newColor, size, pos) {
		cout << "Inside player constructor!" << endl;
	}

	/*
	void setPlayerWidth(float new_width) { 
		
	}
	*/

};