#include "Character.h"

Character::Character(SDL_Renderer* renderer) {
    TextureManager::Instance()->load("sprites.png", "character", renderer);
    init("character", 0, 0, 51, 100, 12);
}

void Character::nextPosition(SDL_Rect* nextRect) {
    Vector2D newPosition = *position;
    int speed = 10;
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        newPosition += Vector2D(-speed, 0);
    }
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        newPosition += Vector2D(speed, 0);
    }
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        newPosition += Vector2D(0, -speed);
    }
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        newPosition += Vector2D(0, speed);
    }
    nextRect->x = newPosition.getX();
    nextRect->y = newPosition.getY();
    nextRect->w = w;
    nextRect->h = h;
}

void Character::update(GameObject* collision) {
    Sprite::update();
    if (collision != NULL) {
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
}
