#include "include/Food.hpp"
#include "include/Game.hpp"

Food::Food(int p_x, int p_y)
{
    posX = p_x;
    posY = p_y;
}

void Food::render()
{
    SDL_Rect food;
    food.x = (posX*40) + 15;
    food.y = (posY*40) + 15;
    food.h = 10;
    food.w = 10;

    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(Game::renderer, &food);
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
}