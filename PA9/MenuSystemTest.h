#pragma once
#include "standard_dependency.h"
#include "StateManager.h"
#include "MenuState.h"

class MenuSystemTest
{
public:
   void RunMenu();

private:
   StateManager gameStates;
};