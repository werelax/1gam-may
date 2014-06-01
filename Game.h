#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_Image.h>
#include "GameObject.h"
#include "Character.h"
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
    void clean();

    SDL_Renderer* getRenderer() { return renderer; }
    void addGameObject(GameObject* sprite);
    void addCharacter(Character* player);

 private:

    SDL_Window* window;
    SDL_Renderer* renderer;

    Character* player;
    std::list<GameObject*> gameObjects;
};

#endif
