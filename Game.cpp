#include "Game.hpp"
#include "TextureManager.h"

SDL_Texture* sprites[2];
SDL_Rect transformers[1];

//SDL_Texture* playerTexture;
//SDL_Texture* test;
Game::Game()
{

}
Game::~Game()
{

}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0 )
    {
        cout << "subsystem Init" << endl;

        window = SDL_CreateWindow(title, x, y, width, height, flags);
        if(window)
        {
            cout << "window created" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255,255,255,255);
            cout << "renderer created" << endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    sprites[0] = TextuteManager::LoadTexture("assets/player.png", renderer);
    sprites[1] = TextuteManager::LoadTexture("assets/test.png", renderer);
    
}
void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_w:
                transformers[0].y = count;
                break;
            case SDLK_s:
                transformers[0].y -= 10;
                break;
            case SDLK_a:
                transformers[0].x -= 10;
                break;
            case SDLK_d:
                transformers[0].x += 10;
                break;
            case SDLK_q:
                isRunning = false;
                break;
          }
          break;
        
        default:
            break;
    }   
}

void Game::update()
{
    count++;

    //PLAYER


    transformers[0].h = 32;
    transformers[0].w = 32;
    transformers[0].x = 50;
    transformers[0].y = 50;

    //TILE
    transformers[1].h = 32;
    transformers[1].w = 32;

    

    cout << count << endl;
}
void Game::render()
{
    SDL_RenderClear(renderer);
    //adding stuff here to render everything
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            transformers[1].x = j * 32;
            transformers[1].y = i * 32;

            SDL_RenderCopy(renderer, sprites[1], NULL, &transformers[1]);
        }

    }
    
    SDL_RenderCopy(renderer, sprites[0], NULL, &transformers[0]);
    
    //--------------------------------
    
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "closing app" << endl;
}
