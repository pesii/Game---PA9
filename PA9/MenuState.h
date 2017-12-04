#include "State.h"
#include "standard_dependency.h"
#include "StateManager.h"
#include <SFML/Audio.hpp>

class MenuState : public State
{
public:
   MenuState(StateManager * gameStateManager);
   ~MenuState() {}

   void Init();
   void Update();
   void HandleInput();
   void Draw();

private:
   int menu_selection;
   StateManager * gameStates;
   sf::Sprite mBackground;
   sf::Font mFont;
   //sf::Music mMusic;

   sf::Text option1, option2, option3;
   sf::RectangleShape select_box;
   int select_pos;
   int select_positions[3];

};