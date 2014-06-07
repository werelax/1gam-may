#ifndef __Character__
#define __Character__

#include "Sprite.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include <SDL2/SDL.h>

class Character : public Sprite
{
public:
    Character(SDL_Renderer* renderer);
    void update(GameObject* collision);
    void nextPosition(SDL_Rect *rect);
};

#endif
