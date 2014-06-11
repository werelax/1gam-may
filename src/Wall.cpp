#include "Wall.hpp"

void Wall::draw(SDL_Renderer &renderer) {
    SDL_SetRenderDrawColor(&renderer, 0, 0, 0, 1);
    SDL_Rect rect;
    rect.x = position.getX();
    rect.y = position.getY();
    rect.w = w; rect.h = h;
    SDL_RenderFillRect(&renderer, &rect);
}

void Wall::update() {
}
