#pragma once

#include "State.h"
#include "standard_dependency.h"
#include "StateManager.h"

class SplashState : public State
{
public:
   SplashState(StateManager * gameStates);
   ~SplashState() {}

   void Init();
   void Update();
   void HandleInput();
   void Draw();

private:

   StateManager * gameStates;
   sf::Sprite mBackground;
   sf::Font mFont;
   
   sf::Text SplashText1, SplashText2, SplashText3, SplashText4;

};