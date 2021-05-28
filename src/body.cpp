#include <SDL2/SDL.h>

#include "include/Body.hpp"
#include "include/Game.hpp"

void Body::render()
{
    SDL_SetRenderDrawColor(Game::renderer, 255,255,255,255);

    SDL_Rect center;
    center.x = (x*40) + 8;
    center.y = (y*40) + 8;
    center.h = 24;
    center.w = 24;

    SDL_RenderFillRect(Game::renderer, &center);

    if(previous != NULL)
    {
        SDL_Rect neck;
        if(previous->x - x == -1)
        {
            neck.x = (x*40) - 8;
            neck.y = (y*40) + 8;
            neck.h = 24;
            neck.w = 16;
        }
        else if(previous->x - x == 1)
        {
            neck.x = (x*40) + 32;
            neck.y = (y*40) + 8;
            neck.h = 24;
            neck.w = 16;
        }
        else if(previous->y - y == -1)
        {
            neck.x = (x*40) + 8;
            neck.y = (y*40) - 8;
            neck.h = 16;
            neck.w = 24;
        }
        else if(previous->y - y == 1)
        {
            neck.x = (x*40) + 8;
            neck.y = (y*40) + 32;
            neck.h = 16;
            neck.w = 24;
        }

        SDL_RenderFillRect(Game::renderer, &neck);
    }
    if(next != NULL)
        next->render();
    
}