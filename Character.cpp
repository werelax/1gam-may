#include "Character.h"

Character::Character(SDL_Renderer* renderer) {
    TextureManager::Instance()->load("sprites.png", "character", renderer);
    init("character", 0, 0, 51, 100, 12);
}

void Character::update() {
    Sprite::update();
    int speed = 10;
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        *position += Vector2D(-speed, 0);
    }
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        *position += Vector2D(speed, 0);
    }
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        *position += Vector2D(0, -speed);
    }
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        *position += Vector2D(0, speed);
    }
}
