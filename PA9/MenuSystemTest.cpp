/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description:
*/
#include "MenuSystemTest.h"

void MenuSystemTest::RunMenu()
{
   this->gameStates.AddState(new SplashState(&gameStates)); 
   this->gameStates.AddState(new MenuState(&gameStates));
   
}
