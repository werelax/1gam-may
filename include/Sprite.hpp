#ifndef __Sprite__
#define __Sprite__

#include "GameObject.hpp"
#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_Image.h>
#include <string>

class Sprite: public GameObject
{
public:
    Sprite() {};
    Sprite(std::string textureid, int x, int y, int spritew, int spriteh,
           int nframes = 0, int row = 0, int currentFrame = 0);
    ~Sprite();
    virtual void init(std::string textureid, int x, int y, int spritew, int spriteh,
                      int nframes = 0, int row = 0, int currentFrame = 0);
    virtual void draw(SDL_Renderer* renderer);
    virtual void update();

protected:
    int nframes;
    int row;
    int currentFrame;
    std::string id;
    SDL_Renderer *renderer;
};

#endif
