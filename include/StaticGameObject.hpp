#pragma once

#include <SDL2/SDL.h>
#include "GameObject.hpp"

class StaticGameObject: public GameObject
{
public:
    StaticGameObject(int x = 0, int y = 0, int iw = 0, int ih = 0):
        GameObject(x, y, iw, ih) {};
    ~StaticGameObject() {};
};
