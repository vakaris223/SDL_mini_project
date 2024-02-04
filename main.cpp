#include <SDL2/SDL.h>
#include "Game.hpp"

using namespace std;

Game *game = nullptr;
int main(int argc, char* argv[]) {

    /*while(game is running)
    {
        handle anu user in put
        update all object eg. positions etc.
        render changes to the display
    }*/


    game = new Game();

    game -> init("hi",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600, false);
    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    
    return 0;
}
