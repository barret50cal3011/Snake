#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Snake.hpp"
#include "Food.hpp"

struct Game
{
    void init(SDL_Window* window);
    bool handleEvents();
    void update();
    void render();

    static SDL_Renderer* renderer;
    Snake* snake;
    Food* food;
};