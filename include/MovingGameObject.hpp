#pragma once

#include <SDL2/SDL.h>
#include "GameObject.hpp"

class MovingGameObject: public GameObject
{
public:
    MovingGameObject(int x = 0, int y = 0, int iw = 0, int ih = 0):
        GameObject(x, y, iw, ih) {};
    ~MovingGameObject() {};

    void setSpeed(float vx, float vy, float mod = 1);
    Vector2D* getSpeed();

    Vector2D* speed;
};
