#ifndef __Sprite__
#define __Sprite__

#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_Image.h>

class Sprite
{
 public:
    Sprite(const char* sheetpath, int x, int y, int spritew, int spriteh,
           int frames, SDL_Renderer* ren);
    ~Sprite() {};

    void update();
    void draw();

    int xpos;
    int ypos;

 private:
    int nframes;
    int currentFrame;
    int w;
    int h;
    SDL_Texture *texture;
    SDL_Renderer *renderer;
};

#endif
