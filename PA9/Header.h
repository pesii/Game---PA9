#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 900
#define PLAYER_WIDTH 30
#define PLAYER_HEIGHT 20
#define ENEMY_WIDTH 30
#define ENEMY_HEIGHT 20

using namespace std;


class Player: public sf::RectangleShape {
public:
	Player(sf::Color const &newColor, sf::Vector2f const &size, sf::Vector2f const &pos);

private:

};

class Projectile: public sf::CircleShape {
public:
	Projectile();
	Projectile(const sf::Color & color, const float & radius, const sf::Vector2f & position);


private:

};

class Game {
public:
	Game();
	void runGame();
	void moveProjectiles(vector<Projectile*> &projectiles);

};