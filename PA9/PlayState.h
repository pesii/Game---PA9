/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description:
*/
#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "standard_dependency.h"
#include "StateManager.h"
#include "SplashState.h"
#include "MenuState.h"
#include "MenuSystemTest.h"
#include "Game.h"
#include <SFML/Audio.hpp>

//template <class t>
class PlayState : public State
{
public:
   PlayState(StateManager * gameStateManager);
   ~PlayState() {
		DestroyTheThing(projectiles, enemies);
   }

   void Init();
   void Update();
   void HandleInput();
   void Draw();

   void DestroyTheThing(vector<Projectile *> proj, vector<Enemy*> enem) {
		for(int i = 0; i < proj.size(); i++) {
			cout << "Destroyed projectile" << endl;
			delete projectiles.at(i);
			projectiles.erase(projectiles.begin());
      }

		for(int i = 0; i < enem.size(); i++) {
			cout << "Destroyed enemies" << endl;
			delete enem.at(i);
			enem.erase(enem.begin());
      }
   }

private:
   void moveProjectiles(vector<Projectile*> &projectiles);
   void moveEnemies(vector<Enemy *>& enemies);

   StateManager * gameStates;

   Player thePlayer;

   //Enemy enemy1, enemy2, enemy3, enemy4, enemy5;

   vector<Projectile*> projectiles;
   vector<Enemy*> enemies;
   sf::FloatRect enemyHitbox;
   bool leftisPressed, rightisPressed, fireKeyPressed;
   time_t time_accumulator;
   long int last_time;
};

#endif