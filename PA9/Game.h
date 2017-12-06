/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description:
*/
#ifndef GAME_H
#define GAME_H

#include "standard_dependency.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
	Game();
	void runGame();
	void moveProjectiles(vector<Projectile*> &projectiles);
};

#endif