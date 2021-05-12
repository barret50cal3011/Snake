#include <iostream>
#include <SDL2/SDL.h>

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

    char runnning = 1;

    while(runnning)
    {
        SDL_Event evt;
        SDL_PollEvent(&evt);

        switch (evt.type)
        {
        case SDL_QUIT:
            runnning = false;
            break;
        }
    }

    return 0;
}