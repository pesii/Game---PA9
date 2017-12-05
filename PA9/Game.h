#pragma once

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