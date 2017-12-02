#include "MenuState.h"

void MenuState::Update()
{
   cout << "In the menu" << endl;
   cout << "1. Start" << endl;
   cout << "2. Credits" << endl;

   this->HandleInput();
}

void MenuState::HandleInput()
{
   cin << menu_selection << endl;
}

