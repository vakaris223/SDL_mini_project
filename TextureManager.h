#pragma once

#include "Game.h"

class TextuteManager
{
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* tex_renderer);
};