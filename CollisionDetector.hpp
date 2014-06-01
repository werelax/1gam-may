#pragma once

#include <SDL2/SDL.h>

class Collisions
{
public:
    static bool aabbTest(SDL_Rect* rect1, SDL_Rect* rect2) {
        return !((rect1->x + rect1->w) < rect2->x ||
                 (rect2->x + rect2->w) < rect1->x ||
                 (rect1->y + rect1->h) < rect2->y ||
                 (rect2->y + rect2->h) < rect1->y);
    }

private:
};
