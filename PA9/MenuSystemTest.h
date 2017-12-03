#pragma once
#include "standard_dependency.h"
#include "StateManager.h"
#include "MenuState.h"
#include "SplashState.h"
#include "CreditsState.h"

class MenuSystemTest
{
public:
   void RunMenu();

private:
   StateManager gameStates;
};