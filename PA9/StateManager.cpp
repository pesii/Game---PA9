#include "StateManager.h"

StateManager::StateManager()
{
   // Update Window
   window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Menu", sf::Style::Close | sf::Style::Titlebar);

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
      //State * delState = allStates.top();
      allStates.pop();
      //delete delState;
   }

   if (!allStates.empty())
   {
      allStates.top()->Update();
   }
}

State * StateManager::GetActiveState()
{
   return allStates.top();
}
