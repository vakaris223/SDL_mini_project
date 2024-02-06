#pragma once
#include "Game.h"
#include "GameObject.h"

class InputManager
{
public:
    GameObject *obj;
    void doKeyDown(SDL_KeyboardEvent *event);
    void doKeyUp(SDL_KeyboardEvent *event);
private:


};