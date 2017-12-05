#include "AssetManager.h"

void AssetManager::loadTexture(std::string name, const std::string filepath)
{
   sf::Texture tex;

   if (tex.loadFromFile(filepath))
   {
      Textures[name] = tex;
   }
}

sf::Texture & AssetManager::getTexture(std::string name)
{
   return Textures[name];
}

void AssetManager::loadFont(std::string name, std::string filepath)
{
   sf::Font font;

   if (font.loadFromFile(filepath))
   {
      Fonts[name] = font;
   }
}

sf::Font & AssetManager::getFont(std::string name)
{
   return Fonts[name];
}