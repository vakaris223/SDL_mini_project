#include "InputManager.h"



void InputManager::doKeyDown(SDL_KeyboardEvent *event)
{
    if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			obj->up = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			obj->down = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			obj->left = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			obj->right = 1;
		}
	}
}
void InputManager::doKeyUp(SDL_KeyboardEvent *event)
{
    if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			obj->up = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			obj->down = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			obj->left = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			obj->right = 0;
		}
	}
}