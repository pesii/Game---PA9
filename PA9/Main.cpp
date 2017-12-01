#include "Header.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 900), "l337");

	Player thePlayer(sf::Color::Green, sf::Vector2f(10, 10), sf::Vector2f(0, window.getSize().y - (10)));

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
			//The following will decide which projectile to create, by checking which projectiles are already made
			if (!projectile1.getRadius() > 0) {
				projectile1.Load(sf::Color::Red, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile2.getRadius() > 0) {
				projectile2.Load(sf::Color::Red, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile3.getRadius() > 0) {
				projectile3.Load(sf::Color::Red, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile4.getRadius() > 0) {
				projectile4.Load(sf::Color::Red, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile5.getRadius() > 0) {
				projectile5.Load(sf::Color::Red, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile6.getRadius() > 0) {
				projectile6.Load(sf::Color::Red, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile7.getRadius() > 0) {
				projectile7.Load(sf::Color::Red, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile8.getRadius() > 0) {
				projectile8.Load(sf::Color::Red, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile9.getRadius() > 0) {
				projectile9.Load(sf::Color::Red, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			else if (!projectile10.getRadius() > 0) {
				projectile10.Load(sf::Color::Red, 5, sf::Vector2f(thePlayer.getPosition().x, thePlayer.getPosition().y));
			}
			fireKeyPressed = false;
		}

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

		window.clear();

		window.draw(thePlayer);

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

		window.display();
	}

	return 0;
}