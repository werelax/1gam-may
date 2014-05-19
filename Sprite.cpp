#include "Sprite.h"
#include <iostream>

Sprite::Sprite(const char* sheetpath, int x, int y, int spritew, int spriteh,
               int frames, SDL_Renderer* ren) {
    currentFrame = 0;
    xpos = x;
    ypos = y;
    nframes = frames;
    w = spritew;
    h = spriteh;
    renderer = ren;
    if (renderer == nullptr) {
        std::cout << "Renderer not initialized!" << std::endl;
    }
    SDL_Surface* tempSurface = IMG_Load(sheetpath);
    if (tempSurface == nullptr) {
        std::cout << "cannot load the sprite: " << sheetpath << std::endl;
    } else {
        std::cout << "image loaded OK" << std::endl;
    }
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    if (texture == nullptr) {
        std::cout << "cannot load the surface: " << sheetpath << std::endl;
    } else {
        std::cout << "surface loaded OK" << std::endl;
    }
    SDL_FreeSurface(tempSurface);
}

void Sprite::draw() {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = currentFrame * w;
    srcRect.y = 0;
    srcRect.w = destRect.w = w;
    srcRect.h = destRect.h = h;
    destRect.x = xpos;
    destRect.y = ypos;
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

void Sprite::update() {
    currentFrame = int((SDL_GetTicks() / 100) % nframes);
}
