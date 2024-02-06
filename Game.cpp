#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "InputManager.h"

GameObject* player;
GameObject* tile;

InputManager manager;

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
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "renderer created" << endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    player = new GameObject("assets/player.png", renderer, 100,100);
    tile = new GameObject("assets/test.png", renderer, 1, 1);
    manager.obj = player;
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
            case SDLK_q:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
				manager.doKeyDown(&event.key);
				break;
			case SDL_KEYUP:
				manager.doKeyUp(&event.key);
				break;
          }
          break;
        
        default:
            break;
    }   

   
}

void Game::update()
{
    player -> Update();
    if (player->up)
		{
			player->ypos -= 4;
		}

		if (player->down)
		{
			player->ypos += 4;
		}

		if (player->left)
		{
			player->xpos -= 4;
		}

		if (player->right)
		{
			player->xpos += 4;
		}

    tile -> Update();

}
void Game::render()
{
    SDL_RenderClear(renderer);
    //adding stuff here to render everything
    player->Render();
    tile->Render();
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
