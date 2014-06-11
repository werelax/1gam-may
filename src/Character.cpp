#include "Character.hpp"

Character::Character(SDL_Renderer* renderer) {
    TextureManager::Instance()->load("./assets/sprites.png", "character", renderer);
    init("character", 0, 0, 51, 100, 12);
    setSpeed(1, 1, 10);
}

void Character::nextPosition(SDL_Rect &nextRect) {
    Vector2D newPosition = position;
    advance(newPosition);
    nextRect.x = newPosition.getX();
    nextRect.y = newPosition.getY();
    nextRect.w = w;
    nextRect.h = h;
}

void Character::update() {
    Sprite::update();
    advance(position);
}

void Character::advance(Vector2D &position) {
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        position += Vector2D(-speed->getX(), 0);
    }
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        position += Vector2D(speed->getY(), 0);
    }
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        position += Vector2D(0, -speed->getY());
    }
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        position += Vector2D(0, speed->getY());
    }
}
