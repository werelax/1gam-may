#include "Game.hpp"
#include "TextureManager.hpp"
#include <iostream>
#include <stdlib.h>
#include "Collisions.hpp"

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

    // Update game objects
    std::list<GameObject*>::iterator i;
    for (i = gameObjects.begin(); i != gameObjects.end(); ++i) {
        (*i)->update();
    }

    // TODO: DOING: CONTINUE:
    // TL;DR: player-wall collision = correction && NOT movement-prevention;
    // The following code is the shittiest thing. Maybe its ok for bullet-type
    // collision, but its terrible for player-wall collision.
    // The idea here is to first move the player and *then* apply the correction
    // so collisions in one axis doesn't affect the other. (look for the cool
    // correction algorithm).

    // Update the player, with possible collision
    SDL_Rect playerPos;
    SDL_Rect wallPos;
    GameObject* collision = NULL;
    player->nextPosition(&playerPos);
    for (i = gameObjects.begin(); i != gameObjects.end(); i++) {
        (*i)->getRect(&wallPos);
        if (Collisions::aabbTest(&playerPos, &wallPos)) {
            collision = *i;
            break;
        }
    }
    player->update(collision);

}

void Game::addGameObject(GameObject* gobject) {
    gameObjects.push_back(gobject);
}

void Game::addCharacter(Character* player) {
    this->player = player;
}
