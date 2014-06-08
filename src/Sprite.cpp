#include "Sprite.hpp"
#include "TextureManager.hpp"

Sprite::Sprite(std::string textureid, int x, int y, int spritew, int spriteh,
               int nframes, int row, int currentFrame) {
    init(textureid, x, y, spritew, spriteh, nframes, row, currentFrame);
}

Sprite::~Sprite() {
}

void Sprite::init(std::string textureid, int x, int y, int spritew, int spriteh,
                  int nframes, int row, int currentFrame) {
    id = textureid;
    position = new Vector2D(x, y);
    w = spritew;
    h = spriteh;
    this->nframes = nframes;
    this->row = row;
    this->currentFrame = currentFrame;
}

void Sprite::draw(SDL_Renderer* renderer) {
    TextureManager::Instance()->drawFrame(id, round(position->getX()),
                                          round(position->getY()), w, h, row,
                                          currentFrame);
}

void Sprite::update() {
    currentFrame = int((SDL_GetTicks() / 100) % nframes);
}
