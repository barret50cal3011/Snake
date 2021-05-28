#include <iostream>

#include "include/Snake.hpp"
#include "include/Game.hpp"

Snake::Snake(int p_x, int p_y, const char* image)
{
    x = p_x;
    y = p_y;

    src.w = 10;
    src.h = 10;

    head = IMG_LoadTexture(Game::renderer ,image);
    if(head == NULL)
        std::cout << "faild to load texture" << std::endl;

    body = new Body();
}

void Snake::update()
{
    body->x = x;
    body->y = y;

    x += dirX;
    y += dirY;

    //sets the rectangle to retreeve the image of the head needed
    if(!dirX && dirY == 1)
    {
        src.x = 0;
        src.y = 0;
    }
    if(!dirX && dirY == -1)
    {
        src.x = 10;
        src.y = 10;
    }
    if(!dirY && dirX == -1)
    {
        src.x = 10;
        src.y = 0;
    }
    if(!dirY && dirX == 1)
    {
        src.x = 0;
        src.y = 10;
    }
}

void Snake::render()
{
    body->render();

    SDL_Rect dst;
    dst.x = x*40;
    dst.y = y*40;
    dst.h = 40;
    dst.w = 40;

    SDL_RenderCopy(Game::renderer, head, &src, &dst);

    SDL_Rect neck;
    if(dirX == 1)
    {
        neck.x = (x*40) - 8;
        neck.y = (y*40) + 8;
        neck.h = 24;
        neck.w = 8;
    }
    else if(dirX == -1)
    {
        neck.x = (x*40) + 40;
        neck.y = (y*40) + 8;
        neck.h = 24;
        neck.w = 8;
    }
    else if(dirY == 1)
    {
        neck.x = (x*40) + 8;
        neck.y = (y*40) - 8;
        neck.h = 8;
        neck.w = 24;
    }
    else if(dirY == -1)
    {
        neck.x = (x*40) + 8;
        neck.y = (y*40) + 40;
        neck.h = 8;
        neck.w = 24;
    }

    SDL_RenderFillRect(Game::renderer, &neck);
}