#include "State.h"
#include "standard_dependency.h"
#include "StateManager.h"

class CreditsState : public State
{
public:
   CreditsState(StateManager * gameStateManager);

   void Init();
   void Update();
   void HandleInput();
   void Draw();

private:
   std::string message;
   StateManager * gameStates;
   sf::Sprite mBackground;
   sf::Font mFont;

   sf::Text name1, name2, name3, name4;
};