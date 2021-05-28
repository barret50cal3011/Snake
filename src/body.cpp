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
    
}