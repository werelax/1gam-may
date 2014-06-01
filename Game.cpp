#include "Game.h"
#include "TextureManager.h"
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

    return true;
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    std::list<GameObject*>::iterator i;
    for (i = gameObjects.begin(); i != gameObjects.end(); ++i) {
        (*i)->draw(renderer);
    }
    player->draw(renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::update() {
    // SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256,
    //                        rand() % 256);
    std::list<GameObject*>::iterator i;
    for (i = gameObjects.begin(); i != gameObjects.end(); ++i) {
        (*i)->update();
    }
    // TODO: DOING:
    // 1. Ghost-move the player (maybe with a method that returns a SDL_Rect)
    // 2. Check the ghost against the walls with Collisions::aabbTest()
    // 3. If collision: (TEMPORAL) prevent the move!
    // 4. If not: do the actual movement
    player->update();

}

void Game::addGameObject(GameObject* gobject) {
    gameObjects.push_back(gobject);
}

void Game::addCharacter(Character* player) {
    this->player = player;
}
