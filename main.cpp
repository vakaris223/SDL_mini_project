#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.hpp"

using namespace std;

Game *game = nullptr;
int main(int argc, char* argv[]) {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    /*while(game is running)
    {
        handle anu user in put
        update all object eg. positions etc.
        render changes to the display
    }*/


    game = new Game();

    game -> init("app",SDL_WINDOWPOS_CENTERED ,SDL_WINDOWPOS_CENTERED ,800,600, false);
    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    game->clean();
    
    return 0;
}
