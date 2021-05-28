#include <iostream>
#include <cstdlib>

#include "include/Snake.hpp"
#include "include/Food.hpp"
#include "include/Game.hpp"

SDL_Renderer* Game::renderer = NULL;

void Game::init(SDL_Window* window)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    snake = new Snake(10, 3, "res/Snake_Head.png");
    snake->dirX = 0;
    snake->dirY = 0;
    food = new Food(10, 9);
}

bool Game::handleEvents()
{
    SDL_Event evt;
    while(SDL_PollEvent(&evt))
    {

        switch(evt.type)
        {
        case SDL_QUIT: 
            return false;
            break;
        case SDL_KEYDOWN:
            int code = evt.key.keysym.scancode;

            if(code == SDL_SCANCODE_W)
            {
                std::cout << "w" << std::endl;
                if(!snake->dirY)
                {
                    snake->dirY = -1;
                    snake->dirX = 0;
                }
                
            }

            if(code == SDL_SCANCODE_S)
            {
                std::cout << "s" << std::endl;
                if(!snake->dirY)
                {
                    snake->dirY = 1;
                    snake->dirX = 0;
                }
                
            }
                
            if(code == SDL_SCANCODE_A)
            {
                std::cout << "a" << std::endl;
                if(!snake->dirX)
                {
                    snake->dirY = 0;
                    snake->dirX = -1;
                }
            }

            if(code == SDL_SCANCODE_D)
            {
                std::cout << "d" << std::endl;
                if(!snake->dirX)
                {
                    snake->dirY = 0;
                    snake->dirX = 1;
                }
            }
        }

    }
    return true;
}

void Game::update()
{
    snake->update();
    if(snake->x == food->posX && snake->y == food->posY)
    {
        srand((unsigned int)time(NULL));
        int x = rand() % 20;
        int y = rand() % 20;

        food = new Food(x, y);
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);

    snake->render();
    food->render();

    SDL_RenderPresent(renderer);
}