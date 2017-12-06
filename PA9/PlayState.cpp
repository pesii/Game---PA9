#include "PlayState.h"

PlayState::PlayState(StateManager * gameStateManager)
{
   this->gameStates = gameStateManager;
}

void PlayState::Init()
{
   time_accumulator = time(0);
   last_time = 0;

   //::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "In Development");

   //Player thePlayer(sf::Color::Green, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), sf::Vector2f(0, SCREEN_HEIGHT - PLAYER_HEIGHT));
   //Player enemy(sf::Color::Red, sf::Vector2f(30, 30), sf::Vector2f(gameStates->window.getSize().y / 2, gameStates->window.getSize().y / 2));

   thePlayer.setFillColor(sf::Color::Green);
   thePlayer.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
   thePlayer.setPosition(sf::Vector2f(0, SCREEN_HEIGHT - PLAYER_HEIGHT));

   enemy1.setFillColor(sf::Color::Red);
   enemy1.setSize(sf::Vector2f(30, 20));
   enemy1.setPosition(sf::Vector2f(0, 0));

   enemy2.setFillColor(sf::Color::Cyan);
   enemy2.setSize(sf::Vector2f(30, 20));
   enemy2.setPosition(sf::Vector2f(200, 0));

   enemy3.setFillColor(sf::Color::Green);
   enemy3.setSize(sf::Vector2f(30, 20));
   enemy3.setPosition(sf::Vector2f(100, 0));

   enemy4.setFillColor(sf::Color::White);
   enemy4.setSize(sf::Vector2f(30, 20));
   enemy4.setPosition(sf::Vector2f(400, 0));

   enemy5.setFillColor(sf::Color::Yellow);
   enemy5.setSize(sf::Vector2f(30, 20));
   enemy5.setPosition(sf::Vector2f(500, 0));

   //Enemy enemy1(sf::Color::Red, sf::Vector2f(30, 20), sf::Vector2f(0, 0));
   //Enemy enemy2(sf::Color::Cyan, sf::Vector2f(30, 20), sf::Vector2f(200, 0));
   //Enemy enemy3(sf::Color::Green, sf::Vector2f(30, 20), sf::Vector2f(100, 0));
   //Enemy enemy4(sf::Color::White, sf::Vector2f(30, 20), sf::Vector2f(400, 0));
   //Enemy enemy5(sf::Color::Yellow, sf::Vector2f(30, 20), sf::Vector2f(500, 0));

   //vector<Projectile*> projectiles;
   //vector<Enemy*> enemies;

   //sf::FloatRect enemyHitbox;

   bool leftisPressed = false;
   bool rightisPressed = false;
   bool fireKeyPressed = false;

}

void PlayState::Update()
{
   Draw();
   HandleInput();
}

void PlayState::HandleInput()
{
   while (gameStates->window.isOpen())
   {
      time_accumulator = time(0);

      sf::Event event;

      while (gameStates->window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
            gameStates->window.close();
         if (event.type == sf::Event::KeyPressed)
         {
            if (!leftisPressed && event.key.code == sf::Keyboard::S)
            {
               leftisPressed = true;
               cout << "S" << endl;
            }
            if (!rightisPressed && event.key.code == sf::Keyboard::D)
            {
               rightisPressed = true;
               cout << "D" << endl;
            }
            if (!fireKeyPressed && event.key.code == sf::Keyboard::A)
            {
               fireKeyPressed = true; 
               cout << "A" << endl;
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
      if (fireKeyPressed == true)
      {
         if (time_accumulator - last_time >= 1)
         {
            //	cout << "Fire key pressed!\n";
            Projectile * p1 = new Projectile(sf::Color::Red, 5, thePlayer.getPosition());
            projectiles.push_back(p1);
            fireKeyPressed = false;
            last_time = time_accumulator;
         }
         
         fireKeyPressed = false;
      }


   moveProjectiles(projectiles);
   Draw();

   }

}

void PlayState::Draw()
{
   gameStates->window.clear();

   gameStates->window.draw(thePlayer);

   //this loop checks if there is anything in the projectiles vector, and draws them
   if (projectiles.size() > 0) {
      for (int i = 0; i < projectiles.size(); i++) {
         gameStates->window.draw(*projectiles.at(i));
      }
   }
   gameStates->window.draw(enemy1);
   gameStates->window.draw(enemy2);
   gameStates->window.draw(enemy3);
   gameStates->window.draw(enemy4);
   gameStates->window.draw(enemy5);

   gameStates->window.display();

   enemy1.move(sf::Vector2f(0, ENEMY_SPEED));
   enemy2.move(sf::Vector2f(0, ENEMY_SPEED));
   enemy3.move(sf::Vector2f(0, ENEMY_SPEED));
   enemy4.move(sf::Vector2f(0, ENEMY_SPEED));
   enemy5.move(sf::Vector2f(0, ENEMY_SPEED));

}

void PlayState::moveProjectiles(vector<Projectile*>& projectiles)
{
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
