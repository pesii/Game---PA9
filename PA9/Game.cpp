#include "Header.h"

Game::Game() {
	runGame();
}

void Game::runGame() {
	sf::RenderWindow window(sf::VideoMode(1200, 900), "In Development");

	Player thePlayer(sf::Color::Green, sf::Vector2f(10, 10), sf::Vector2f(0, window.getSize().y - (10)));
	Player enemy(sf::Color::Red, sf::Vector2f(30, 30), sf::Vector2f(window.getSize().y / 2, window.getSize().y / 2));

	sf::FloatRect enemyHitbox;

	Projectile projectile1(sf::Color::Red, 0, sf::Vector2f(0, 0));
	Projectile projectile2(sf::Color::Red, 0, sf::Vector2f(0, 0));
	Projectile projectile3(sf::Color::Red, 0, sf::Vector2f(0, 0));
	Projectile projectile4(sf::Color::Red, 0, sf::Vector2f(0, 0));
	Projectile projectile5(sf::Color::Red, 0, sf::Vector2f(0, 0));
	Projectile projectile6(sf::Color::Red, 0, sf::Vector2f(0, 0));
	Projectile projectile7(sf::Color::Red, 0, sf::Vector2f(0, 0));
	Projectile projectile8(sf::Color::Red, 0, sf::Vector2f(0, 0));
	Projectile projectile9(sf::Color::Red, 0, sf::Vector2f(0, 0));
	Projectile projectile10(sf::Color::Red, 0, sf::Vector2f(0, 0));

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
			thePlayer.move(-.1, 0);
		}
		if (rightisPressed == true) {
			thePlayer.move(.1, 0);
		}
		if (fireKeyPressed == true) {
			cout << "Fire key pressed!\n";
			//The following will decide which projectile to create, by checking which projectiles are already made
			//if radius is > 0, projectile already exists on screen
			if (!projectile1.getRadius() > 0) {
				projectile1.Load(sf::Color::Blue, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile2.getRadius() > 0) {
				projectile2.Load(sf::Color::White, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile3.getRadius() > 0) {
				projectile3.Load(sf::Color::Yellow, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile4.getRadius() > 0) {
				projectile4.Load(sf::Color::Green, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile5.getRadius() > 0) {
				projectile5.Load(sf::Color::Cyan, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile6.getRadius() > 0) {
				projectile6.Load(sf::Color::Blue, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile7.getRadius() > 0) {
				projectile7.Load(sf::Color::White, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile8.getRadius() > 0) {
				projectile8.Load(sf::Color::Yellow, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile9.getRadius() > 0) {
				projectile9.Load(sf::Color::Green, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile10.getRadius() > 0) {
				projectile10.Load(sf::Color::Cyan, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			fireKeyPressed = false;
		}

		moveProjectiles(projectile1, projectile2, projectile3, projectile4, projectile5, projectile6, projectile7, projectile8, projectile9, projectile10);
		checkProjectiles(projectile1, projectile2, projectile3, projectile4, projectile5, projectile6, projectile7, projectile8, projectile9, projectile10);

		window.clear();

		window.draw(thePlayer);
		window.draw(enemy);

		window.draw(projectile1);
		window.draw(projectile2);
		window.draw(projectile3);
		window.draw(projectile4);
		window.draw(projectile5);
		window.draw(projectile6);
		window.draw(projectile7);
		window.draw(projectile8);
		window.draw(projectile9);
		window.draw(projectile10);

		enemyHitbox = enemy.getGlobalBounds();
		if (enemyHitbox.contains(projectile1.getPosition()) || enemyHitbox.contains(projectile2.getPosition()) || enemyHitbox.contains(projectile3.getPosition()) || enemyHitbox.contains(projectile4.getPosition()) || enemyHitbox.contains(projectile5.getPosition()) || enemyHitbox.contains(projectile6.getPosition()) || enemyHitbox.contains(projectile7.getPosition()) || enemyHitbox.contains(projectile8.getPosition()) || enemyHitbox.contains(projectile9.getPosition()) || enemyHitbox.contains(projectile10.getPosition())) {
			cout << "Projectile hit enemy\n";
		}

		window.display();

		//cout << "Player coords: " << thePlayer.getPosition().x << ", " << thePlayer.getPosition().y << "\n";

	}
}

void Game::moveProjectiles(Projectile &projectile1, Projectile &projectile2, Projectile &projectile3, Projectile &projectile4, Projectile &projectile5, Projectile &projectile6, Projectile &projectile7, Projectile &projectile8, Projectile &projectile9, Projectile &projectile10) {
	//The following will check the radius of the projectile. If the radius is greater than 0, the projectile "exists", so move it upwards
	if (projectile1.getRadius() > 0) {
		projectile1.move(0, -.1);
	}
	if (projectile2.getRadius() > 0) {
		projectile2.move(0, -.1);
	}
	if (projectile3.getRadius() > 0) {
		projectile3.move(0, -.1);
	}
	if (projectile4.getRadius() > 0) {
		projectile4.move(0, -.1);
	}
	if (projectile5.getRadius() > 0) {
		projectile5.move(0, -.1);
	}
	if (projectile6.getRadius() > 0) {
		projectile6.move(0, -.1);
	}
	if (projectile7.getRadius() > 0) {
		projectile7.move(0, -.1);
	}
	if (projectile8.getRadius() > 0) {
		projectile8.move(0, -.1);
	}
	if (projectile9.getRadius() > 0) {
		projectile9.move(0, -.1);
	}
	if (projectile10.getRadius() > 0) {
		projectile10.move(0, -.1);
	}
}

void Game::checkProjectiles(Projectile &projectile1, Projectile &projectile2, Projectile &projectile3, Projectile &projectile4, Projectile &projectile5, Projectile &projectile6, Projectile &projectile7, Projectile &projectile8, Projectile &projectile9, Projectile &projectile10) {
	//The following checks the position of the 10 possible projectiles. If they go above the y limit, destroy them (set their radius to 0 and reset their position)
	if (projectile1.getPosition().y < 0) {
		projectile1.Destroy();
	}
	if (projectile2.getPosition().y < 0) {
		projectile2.Destroy();
	}
	if (projectile3.getPosition().y < 0) {
		projectile3.Destroy();
	}
	if (projectile4.getPosition().y < 0) {
		projectile4.Destroy();
	}
	if (projectile5.getPosition().y < 0) {
		projectile5.Destroy();
	}
	if (projectile6.getPosition().y < 0) {
		projectile6.Destroy();
	}
	if (projectile7.getPosition().y < 0) {
		projectile7.Destroy();
	}
	if (projectile8.getPosition().y < 0) {
		projectile8.Destroy();
	}
	if (projectile9.getPosition().y < 0) {
		projectile9.Destroy();
	}
	if (projectile10.getPosition().y < 0) {
		projectile10.Destroy();
	}
}
