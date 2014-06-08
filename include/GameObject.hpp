#ifndef __GameObject__
#define __GameObject__

#include <SDL2/SDL.h>
#include "Vector2D.h"

class GameObject
{
 public:
    GameObject(int x = 0, int y = 0, int iw = 0, int ih = 0):
        position(new Vector2D(x, y)), w(iw), h(ih) {};
    ~GameObject() {};

    virtual void update();
    virtual void draw(SDL_Renderer* renderer);
    virtual void getRect(SDL_Rect* rect);

    Vector2D* position;
    int w;
    int h;
};

#endif
