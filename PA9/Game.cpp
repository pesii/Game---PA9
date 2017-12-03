#include "Header.h"
 
Game::Game() {
	runGame();
}

void Game::runGame() {
	time_t realtime;
	long int last_time = 0;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "In Development");

	Player thePlayer(sf::Color::Green, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), sf::Vector2f(0, SCREEN_HEIGHT - PLAYER_HEIGHT));
	Player enemy(sf::Color::Red, sf::Vector2f(30, 30), sf::Vector2f(window.getSize().y / 2, window.getSize().y / 2));
	
	Enemy enemy1(sf::Color::Red, sf::Vector2f(30,20), sf::Vector2f(0, 0));
	Enemy enemy2(sf::Color::Cyan, sf::Vector2f(30, 20), sf::Vector2f(200, 0));
	Enemy enemy3(sf::Color::Green, sf::Vector2f(30, 20), sf::Vector2f(100, 0));
	Enemy enemy4(sf::Color::White, sf::Vector2f(30, 20), sf::Vector2f(400, 0));
	Enemy enemy5(sf::Color::Yellow, sf::Vector2f(30, 20), sf::Vector2f(500, 0));

 	vector<Projectile*> projectiles;
	//vector<Enemy*> enemies;

	sf::FloatRect enemyHitbox;

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
			thePlayer.move(-0.2, 0);
		}
		if (rightisPressed == true) {
			thePlayer.move(0.2, 0);
		}
		if (fireKeyPressed == true) {
		//	cout << "Fire key pressed!\n";
			Projectile* p1 = new Projectile(sf::Color::Red, 5, thePlayer.getPosition());
			projectiles.push_back(p1);
			fireKeyPressed = false;
		}
		
		moveProjectiles(projectiles);

		window.clear();

		window.draw(thePlayer);
		window.draw(enemy);

		//this loop checks if there is anything in the projectiles vector, and draws them
		if (projectiles.size() > 0) {
			for (int i = 0; i < projectiles.size(); i++) {
				window.draw(*projectiles.at(i));
			}
		}
		window.draw(enemy1);
		window.draw(enemy2);
		window.draw(enemy3);
		window.draw(enemy4);
		window.draw(enemy5);

		//enemyHitbox = enemy.getGlobalBounds();
		//if (enemyHitbox.contains(projectile.at(i).getPosition()) || enemyHitbox.contains(projectile2.getPosition()) || enemyHitbox.contains(projectile3.getPosition()) || enemyHitbox.contains(projectile4.getPosition()) || enemyHitbox.contains(projectile5.getPosition()) || enemyHitbox.contains(projectile6.getPosition()) || enemyHitbox.contains(projectile7.getPosition()) || enemyHitbox.contains(projectile8.getPosition()) || enemyHitbox.contains(projectile9.getPosition()) || enemyHitbox.contains(projectile10.getPosition())) {
		//	cout << "Projectile hit enemy\n";
		//}

		window.display();

		enemy1.move(sf::Vector2f(0, ENEMY_SPEED));
		enemy2.move(sf::Vector2f(0, ENEMY_SPEED));
		enemy3.move(sf::Vector2f(0, ENEMY_SPEED));
		enemy4.move(sf::Vector2f(0, ENEMY_SPEED));
		enemy5.move(sf::Vector2f(0, ENEMY_SPEED));

		//cout << "Player coords: " << thePlayer.getPosition().x << ", " << thePlayer.getPosition().y << "\n";
	}
}

void Game::moveProjectiles(vector<Projectile*> &projectiles){
	for (int i = 0; i < projectiles.size(); i++) {
		projectiles.at(i)->move(0, -1);
		
		//this checks if the projectile moved past the screen, if so, de-allocate the object and remove from vector
		if (projectiles.at(i)->getPosition().y < ORIGIN) {
			cout << "Deleted projectile!" << endl;
			delete projectiles.at(i);
			projectiles.erase(projectiles.begin());
		}
	}
}


