#include "State.h"
#include "standard_dependency.h"
#include "StateManager.h"

class MenuState : public State
{
public:
   MenuState(StateManager * gameStateManager);

   void Init();
   void Update();
   void HandleInput();
   void Draw();

private:
   int menu_selection;
   StateManager * gameStates;
   sf::Sprite mBackground;
   sf::Font mFont;

   sf::Text option1, option2, option3;
   sf::RectangleShape select_box;
   int select_pos;
   int select_positions[3];

};