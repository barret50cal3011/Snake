#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Snake
{
    int x, y;
    int direction;
    SDL_Texture* head;

    Snake(int p_x, int p_y, const char* image);
    ~Snake();

    void update();
    void render();
};