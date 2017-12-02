#include "StateManager.h"

void StateManager::AddState(State * newState, bool isReplacing)
{
   if (isReplacing && !allStates.empty())
   {
      allStates.pop();
   }

   if (isAdding)
   {
      allStates.push(newState);
   }

   allStates.top()->Update();
}
