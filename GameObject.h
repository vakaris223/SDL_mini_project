#pragma once
#include "Game.h"

class GameObject
{
public:
    GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
    ~GameObject();

    void Update();
    void Render();

    int xpos;
    int ypos;

    //movement
    int up,down,left,right;

private:

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};