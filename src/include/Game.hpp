#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Game
{
    void init(SDL_Window* window);
    bool handleEvents();
    void update();
    void render();

    static SDL_Renderer* renderer;
    static SDL_Texture* head;
};