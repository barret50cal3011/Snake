#include <iostream>
#include <cstdlib>

#include "include/Snake.hpp"
#include "include/Food.hpp"
#include "include/Game.hpp"

SDL_Renderer* Game::renderer = NULL;

void Game::init(SDL_Window* window)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    snake = new Snake(10, 10, "res/Snake_Head.png");
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
                if(!snake->dirY)
                {
                    snake->dirY = -1;
                    snake->dirX = 0;
                }
            }

            if(code == SDL_SCANCODE_S)
            {
                if(!snake->dirY)
                {
                    snake->dirY = 1;
                    snake->dirX = 0;
                }
                
            }
                
            if(code == SDL_SCANCODE_A)
            {
                if(!snake->dirX)
                {
                    snake->dirY = 0;
                    snake->dirX = -1;
                }
            }

            if(code == SDL_SCANCODE_D)
            {
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
        snake->size++;

        srand((unsigned int)time(NULL));
        int x = rand() % 20;
        int y = rand() % 20;

        food = new Food(x, y);
    }
    else 
        snake->dequeue();

    //look for cases of IMENET DEATH
    if(!(snake->x > -1 && snake->x < 20))
        death();

    if(!(snake->y > -1 && snake->y < 20))
        death();

    for(Body *b = snake->body; b != NULL; b = b->next)
    {
        if(snake->x == b->x && snake->y == b->y && snake->size > 2)
            death();
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);

    snake->render();
    food->render();

    SDL_RenderPresent(renderer);
}

void Game::death()
{
    snake = new Snake(10, 10, "res/Snake_Head.png");

    srand((unsigned int)time(NULL));
    int x = rand() % 20;
    int y = rand() % 20;

    food = new Food(x, y);
}