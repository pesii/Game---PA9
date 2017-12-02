#pragma once

class State
{
public:
   virtual void Update() = 0;
   virtual void HandleInput() = 0;
   //void Pause();
   //void Resume();
   
};