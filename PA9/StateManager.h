#pragma once

#include <stack>
#include "State.h"
#include "Definintions.h"
#include "AssetManager.h"

class StateManager
{
public:
   StateManager();
   ~StateManager() {}

   void AddState(State * newState, bool isReplacing = true);
   void RemoveState();
   State * GetActiveState();

   sf::RenderWindow window;
   AssetManager assets;

private:
   std::stack<State*> allStates;
   

   bool isAdding;
   bool isReplacing;
   bool isRemoving;
};