#include "TextureManager.h"
#include <iostream>

bool TextureManager::load(std::string fileName, std::string id,
                          SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
    if (tempSurface == nullptr) {
        std::cout << "Can't load surface: " << fileName << std::endl;
        return false;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    if (texture == nullptr) {
        std::cout << "Can't load texture for: " << fileName << std::endl;
        return false;
    }
    texture_t textureTuple = {texture, renderer};
    textureMap[id] = textureTuple;
    return true;
}

void TextureManager::draw(std::string id, int x, int y, int width,
                          int height) {
    drawFrame(id, x, y, width, height, 0, 0);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width,
                               int height, int row, int frame) {
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width*frame;
    srcRect.y = height*row;
    srcRect.h = destRect.h = height;
    srcRect.w = destRect.w = width;
    destRect.x = x;
    destRect.y = y;
    texture_t texture = textureMap[id];
    SDL_RenderCopy(texture.renderer, texture.sdl_texture, &srcRect, &destRect);
}

TextureManager* TextureManager::s_instance = 0;

TextureManager* TextureManager::Instance() {
    if (s_instance == 0) {
        s_instance = new TextureManager();
    }
    return s_instance;
}
