#include "Header.h"

Player::Player(sf::Color const &newColor, sf::Vector2f const &size, sf::Vector2f const &pos) {
	{
		this->setFillColor(newColor);
		this->setSize(size);
		this->setPosition(pos);
	}
}