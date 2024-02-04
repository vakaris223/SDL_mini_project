#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

class Game{
public:
    Game();
    ~Game();
    void init(const char* title, int x, int y, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running(){return isRunning;};

private:
    int count = 0; //lets say fps or how fast the game runs
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif /*Game_hpp*/
