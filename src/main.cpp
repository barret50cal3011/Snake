#include <iostream>
#include <SDL2/SDL.h>

#include "include/Game.hpp"

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "error initialising SDL" << std::endl;
        return 1;
    }
        
    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
    if(!window)
    {
        std::cout << "error creating window" << std::endl;
        return 2;
    }

    Game* game = new Game();
    game->init(window);

    char runnning = 1;
    while(runnning)
    {
        runnning = game->handleEvents();
        game->update();
        game->render();
    }

    return 0;
}