#pragma once 

#include "standard_dependency.h"

class AssetManager
{
public:
	void loadTexture(std::string name, std::string filepath);
	sf::Texture & getTexture(std::string name);

	void loadFont(std::string name, std::string filepath);
	sf::Font & getFont(std::string name);

private:
	std::map<std::string, sf::Texture> Textures;
	std::map<std::string, sf::Font> Fonts;

};