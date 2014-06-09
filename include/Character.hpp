#pragma once

#include "Sprite.hpp"
#include "TextureManager.hpp"
#include "InputHandler.hpp"
#include <SDL2/SDL.h>

class Character : public Sprite
{
public:
    Character(SDL_Renderer* renderer);
    void update();
    void nextPosition(SDL_Rect *rect);

protected:
    void advance(Vector2D* positio);
};
