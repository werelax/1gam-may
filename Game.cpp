#include "Game.h"
#include <iostream>
#include <stdlib.h>

bool Game::init(const char* title, int xpos, int ypos, int width, int height,
                int flags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL init success\n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window != 0) {
            std::cout << "window creation success\n";
            renderer = SDL_CreateRenderer(window, -1,
                                          SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer != 0) {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }

    prunning = true;
    return true;
}

void Game::render() {
    SDL_RenderClear(renderer);
    std::list<Sprite*>::iterator i;
    for (i = sprites.begin(); i != sprites.end(); ++i) {
        (*i)->draw();
    }
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            prunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::update() {
    // SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256,
    //                        rand() % 256);
    std::list<Sprite*>::iterator i;
    for (i = sprites.begin(); i != sprites.end(); ++i) {
        (*i)->update();
    }
}

void Game::addSprite(Sprite* sprite) {
    sprites.push_back(sprite);
}
