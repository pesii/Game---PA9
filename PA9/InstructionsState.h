#include "State.h"
#include "standard_dependency.h"
#include "StateManager.h"

class InstructionsState : public State
{
public:
   InstructionsState(StateManager * gameStateManager);
   ~InstructionsState() {};

   void Init();
   void Update();
   void HandleInput();
   void Draw();

private:

   StateManager * gameStates;
   sf::Sprite mBackground;
   sf::Font mFont;

   sf::Text Instruction1, Instruction2, Instruction3, Instruction4, Instruction5;

};