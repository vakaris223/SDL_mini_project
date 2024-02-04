#include "TextureManager.h"
//SDL_RenderCopy(renderer, playerTexture, NULL/*will use entire image*/, NULL/*draw to the whole render frame*/);

SDL_Texture* TextuteManager::LoadTexture(const char* fileName, SDL_Renderer* tex_renderer)
{
    SDL_Surface* tmpSurface = IMG_Load(fileName);
    SDL_Texture* Texture = SDL_CreateTextureFromSurface(tex_renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return Texture;
}