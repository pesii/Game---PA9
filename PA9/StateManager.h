#pragma once

#include <stack>
#include "State.h"

class StateManager
{
public:
   void AddState(State * newState, bool isReplacing = true);

private:
   std::stack<State*> allStates;

   bool isAdding;
   bool isReplacing;
   bool isRemoving;
};