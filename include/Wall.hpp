#ifndef __Wall__
#define __Wall__

#include "GameObject.hpp"
#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_Image.h>
#include <string>

class Wall: public GameObject
{
public:
    Wall() {};
    Wall(int x, int y, int w, int h):
        GameObject(x, y, w, h) {};
    virtual void draw(SDL_Renderer &renderer);
    virtual void update();
    // for calculating collisions against?
    // virtual void getRect(SDL_Rect* rect);

protected:
    std::string textureid;
};


#endif
