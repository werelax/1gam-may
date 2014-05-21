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
    virtual void update();
};

#endif
