#pragma once

#include "standard_dependency.h"

class SpawnObject : public sf::RectangleShape {
public:
	SpawnObject(sf::Color const &newColor, sf::Vector2f const &size, sf::Vector2f const &position)
	{
		cout << "Inside SpawnObject constructor!" << endl;

		setFillColor(newColor);
		setSize(size);
		setPosition(position);
	}

	void virtual setObjWidth(float new_width) {
		obj_width = new_width;
	}
	void setObjHeight(float new_height) {
		obj_height = new_height;
	}
protected:

	float obj_width;
	float obj_height;
};