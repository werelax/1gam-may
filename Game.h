#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_Image.h>
#include "Sprite.h"
#include <list>

class Game
{
 public:
    Game() {};
    ~Game() {};

    bool init(const char* title, int xpos, int ypos, int width, int height,
              int flags);

    void render();
    void update();
    void handleEvents();
    void clean();

    SDL_Renderer* getRenderer() { return renderer; }
    void addSprite(Sprite* sprite);

    bool running() { return prunning; }

 private:

    SDL_Window* window;
    SDL_Renderer* renderer;

    std::list<Sprite*> sprites;

    bool prunning;
};

#endif
