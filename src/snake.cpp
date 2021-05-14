#include <iostream>

#include "include/Snake.hpp"
#include "include/Game.hpp"

Snake::Snake(int p_x, int p_y, const char* image)
{
    x = p_x;
    y = p_y;

    head = IMG_LoadTexture(Game::renderer ,image);
    if(head == NULL)
        std::cout << "faild to load texture" << std::endl;

}

void Snake::update()
{

}

void Snake::render()
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 10;
    src.h = 10;

    SDL_Rect dst;
    dst.x = 100;
    dst.y = 100;
    dst.h = 50;
    dst.w = 50;
    SDL_RenderCopy(Game::renderer, head, &src, &dst);
}