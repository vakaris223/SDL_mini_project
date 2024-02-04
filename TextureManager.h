#pragma once

#include "Game.hpp"

class TextuteManager
{
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* tex_renderer);
};