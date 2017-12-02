#include "Header.h"

Projectile::Projectile() {
	this->setFillColor(sf::Color::Green);
	this->setRadius(5);
	this->setPosition(sf::Vector2f(0,0));
}

Projectile::Projectile(const sf::Color & color, const float & radius, const sf::Vector2f & position) {
	this->setFillColor(color);
	this->setRadius(radius);
	this->setPosition(position);
}

void Projectile::Load(const sf::Color & color, const float & radius, const sf::Vector2f & position) {
	this->setFillColor(color);
	this->setRadius(radius);
	this->setPosition(position);
}

void Projectile::Destroy() {
	this->setRadius(0);
	this->setPosition(sf::Vector2f(0, 0));

}