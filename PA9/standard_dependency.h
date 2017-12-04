#pragma once

// printing runtime messages to the console for debugging
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Definintions.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

#include <vector>
using std::vector;

// time 
#include <ctime>
//using std::time_t;

#include <SFML/Graphics.hpp>

/* Will be rolling out macros. We want to minimize macro use and for the sake of portability and generic-ness
 * we will have the following macros be defined as private members of their rightful classes.
 */
#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 900
#define PLAYER_WIDTH 30
#define PLAYER_HEIGHT 20
#define ENEMY_WIDTH 30
#define ENEMY_HEIGHT 20
#define ENEMY_SPEED 0.0125
#define ORIGIN 0