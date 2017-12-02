#include "State.h"

class CreditsState : public State
{
public:
   CreditsState(std::string message = "People's Names Go Here...");

   void Update();
   void HandleInput();

private:
   std::string message;
};