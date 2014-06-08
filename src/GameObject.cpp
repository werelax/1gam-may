#include "GameObject.hpp"

void GameObject::draw(SDL_Renderer* renderer) {
    // TODO: Make this method abstract
}

void GameObject::update() {
    // TODO: Make this method abstract
}

void GameObject::getRect(SDL_Rect* rect) {
    rect->x = position->getX();
    rect->y = position->getY();
    rect->w = w; rect->h = h;
}
