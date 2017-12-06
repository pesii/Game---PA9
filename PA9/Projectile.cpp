/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description:
*/
#include "Projectile.h"

Projectile::Projectile() {
	this->setFillColor(sf::Color::Green);
	this->setSize(sf::Vector2f(5,10));
	this->setPosition(sf::Vector2f(0,0));
}

Projectile::Projectile(const sf::Color & color, const sf::Vector2f &size, const sf::Vector2f & position) {
	cout << "Inside Projectile Constructor" << endl;
	this->setFillColor(color);
	this->setSize(size);
	this->setPosition(position);

	sf::Texture texture;
	if(!texture.loadFromFile("Bullet.jpg")) {
		cout << "Error loading texture!" << endl;	
	}
	const sf::Texture *pTexture = &texture;

	this->setTexture(&texture);
}


