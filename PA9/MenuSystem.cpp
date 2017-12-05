#include "MenuSystem.h"

void MenuSystem::RunMenu()
{
	this->gameStates.AddState(new SplashState(&gameStates));
	this->gameStates.AddState(new MenuState(&gameStates));

}