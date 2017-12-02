#include "State.h"

class MenuState : public State
{
public:
   void Update();
   void HandleInput();

private:
   int menu_selection;

};