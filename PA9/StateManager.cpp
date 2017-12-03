#include "StateManager.h"

StateManager::StateManager()
{
   

}

void StateManager::AddState(State * newState, bool isReplacing)
{
   this->isAdding = true;
   
   if (isReplacing && !allStates.empty())
   {
      allStates.pop();
   }

   if (isAdding)
   {
      allStates.push(newState);
   }

   allStates.top()->Init();
   allStates.top()->Update();
}

void StateManager::RemoveState()
{
   if (!allStates.empty())
   {
      allStates.pop();
   }

   allStates.top()->Update();
}

State * StateManager::GetActiveState()
{
   return allStates.top();
}
