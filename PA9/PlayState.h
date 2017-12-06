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
#include "Game.h"
#include <SFML/Audio.hpp>

class PlayState : public State
{
public:
   PlayState(StateManager * gameStateManager);
   ~PlayState() {}

   void Init();
   void Update();
   void HandleInput();
   void Draw();

private:
   void moveProjectiles(vector<Projectile*> &projectiles);
   
   StateManager * gameStates;

   Player thePlayer;

   Enemy enemy1, enemy2, enemy3, enemy4, enemy5;

   vector<Projectile*> projectiles;
   sf::FloatRect enemyHitbox;
   bool leftisPressed, rightisPressed, fireKeyPressed;
};