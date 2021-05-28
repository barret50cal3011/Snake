#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Body.hpp"

struct Snake
{
    int x, y;
    int dirX, dirY;
    int size;
    SDL_Texture* head;
    SDL_Rect src;
    Body* body;
    Body* tail;

    Snake(int p_x, int p_y, const char* image);
    ~Snake();

    void update();
    void render();

    void queue();
    void dequeue();
};