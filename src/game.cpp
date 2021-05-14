
#include "include/Snake.hpp"
#include "include/Game.hpp"

SDL_Renderer* Game::renderer = NULL;

void Game::init(SDL_Window* window)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    snake = new Snake(10, 10, "res/Snake_Head.png");
}

bool Game::handleEvents()
{
    SDL_Event evt;
    SDL_PollEvent(&evt);

    switch(evt.type)
    {
    case SDL_QUIT: 
        return false;
    }

    return true;
}

void Game::update()
{

}

void Game::render()
{
    SDL_RenderClear(renderer);

    snake->render();

    SDL_RenderPresent(renderer);
}