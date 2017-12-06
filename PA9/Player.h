/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description:
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "SpawnObjects.h"

class Player: public SpawnObject {
public:
	//create_player(sf::Color const &newColor, float )
	Player(sf::Color const &newColor = sf::Color::Red, 
      sf::Vector2f const &size = sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), 
      sf::Vector2f const &pos = sf::Vector2f(0, SCREEN_HEIGHT - PLAYER_HEIGHT))
		: SpawnObject(newColor, size, pos) {
		cout << "Inside player constructor!" << endl;
	}

	/*
	void setPlayerWidth(float new_width) { 
		
	}
	*/

};
#endif