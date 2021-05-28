#pragma once

#include <SDL2/SDL.h>

struct Food
{
    int posX, posY;
    bool available[400]; 

    Food(int p_x, int p_y);
    ~Food();
    void render();

};