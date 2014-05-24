#ifndef __Wall__
#define __Wall__

#include "GameObject.h"
#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_Image.h>

class Wall: public GameObject
{
public:
    Wall() {};
    virtual void init(std::string textureid, int x, int y, int w, int h);
    virtual void draw(SDL_Renderer* renderer);
    virtual void update();
    // for calculating collisions against?
    virtual void getRect(SDL_Rect* rect);

protected:
}


#endif
