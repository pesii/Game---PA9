#include "MenuSystemTest.h"

void MenuSystemTest::RunMenu()
{
   this->gameStates.AddState(new SplashState(&gameStates)); 
   this->gameStates.AddState(new MenuState(&gameStates));
   
}
