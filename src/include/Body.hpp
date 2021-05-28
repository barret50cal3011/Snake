#pragma once

#include <SDL2/SDL.h>

struct Body
{
    int x, y;
    Body* next;
    Body* previous;

    void render();
};