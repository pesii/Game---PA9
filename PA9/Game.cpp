#include "Header.h"

using std::vector;
 
Game::Game() {
	runGame();
}

void Game::runGame() {
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "In Development");

	Player thePlayer(sf::Color::Green, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), sf::Vector2f(0, SCREEN_HEIGHT - PLAYER_HEIGHT));
	//Player enemy(sf::Color::Red, sf::Vector2f(30, 30), sf::Vector2f(window.getSize().y / 2, window.getSize().y / 2));

	vector<Projectile*> projectiles;

	//sf::FloatRect enemyHitbox;

	bool leftisPressed = false;
	bool rightisPressed = false;
	bool fireKeyPressed = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (!leftisPressed && event.key.code == sf::Keyboard::S)
				{
					leftisPressed = true;
				}
				if (!rightisPressed && event.key.code == sf::Keyboard::D)
				{
					rightisPressed = true;
				}
				if (!fireKeyPressed && event.key.code == sf::Keyboard::A)
				{
					fireKeyPressed = true;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (leftisPressed && event.key.code == sf::Keyboard::S)
				{
					leftisPressed = false;
				}
				if (rightisPressed && event.key.code == sf::Keyboard::D)
				{
					rightisPressed = false;
				}
				if (fireKeyPressed && event.key.code == sf::Keyboard::A)
				{
					fireKeyPressed = false;
				}
			}
		}

		if (leftisPressed == true) {
			thePlayer.move(-1, 0);
		}
		if (rightisPressed == true) {
			thePlayer.move(1, 0);
		}
		if (fireKeyPressed == true) {
			cout << "Fire key pressed!\n";
			Projectile* p1 = new Projectile(sf::Color::Red, 5, thePlayer.getPosition());
			projectiles.push_back(p1);
			fireKeyPressed = false;
		}

		moveProjectiles(projectiles);

		window.clear();

		window.draw(thePlayer);
		//window.draw(enemy);

		//this loop checks if there is anything in the projectiles vector, and draws them
		if (projectiles.size() > 0) {
			for (int i = 0; i < projectiles.size(); i++) {
				window.draw(*projectiles.at(i));
			}
		}

		//enemyHitbox = enemy.getGlobalBounds();
	/*	if (enemyHitbox.contains(projectile1.getPosition()) || enemyHitbox.contains(projectile2.getPosition()) || enemyHitbox.contains(projectile3.getPosition()) || enemyHitbox.contains(projectile4.getPosition()) || enemyHitbox.contains(projectile5.getPosition()) || enemyHitbox.contains(projectile6.getPosition()) || enemyHitbox.contains(projectile7.getPosition()) || enemyHitbox.contains(projectile8.getPosition()) || enemyHitbox.contains(projectile9.getPosition()) || enemyHitbox.contains(projectile10.getPosition())) {
			cout << "Projectile hit enemy\n";
		}*/

		window.display();

		//cout << "Player coords: " << thePlayer.getPosition().x << ", " << thePlayer.getPosition().y << "\n";
	}
}

void Game::moveProjectiles(vector<Projectile*> &projectiles){
	for (int i = 0; i < projectiles.size(); i++) {
		projectiles.at(i)->move(0, -1);
		//this checks if the projectile moved past the screen, if so, de-allocate the object and remove from vector
		if (projectiles.at(i)->getPosition().y > SCREEN_HEIGHT) {
			delete projectiles.at(i);
			projectiles.erase(projectiles.begin());
		}
	}
}


