#include "Game.hpp"


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
        std::cout << "subsystem Init" << std::endl;

        window = SDL_CreateWindow(title, x, y, width, height, flags);
        if(window)
        {
            std::cout << "window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255,255,255,255);
            std::cout << "renderer created" << std::endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
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
            case SDLK_ESCAPE:
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

}
void Game::render()
{
    SDL_RenderClear(renderer);
    //adding stuff here to render everything
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "closing app" << std::endl;
}
