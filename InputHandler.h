#ifndef __InputHandler__
#define __InputHandler__

#include <SDL2/SDL.h>

class InputHandler
{
 public:
    void update();
    void clean();

    bool isKeyDown(SDL_Scancode key);
    bool shouldQuit();

    static InputHandler* Instance();

 private:
    InputHandler(): keystates(NULL) {};
    ~InputHandler() {};

    void onKeyUp();
    void onKeyDown();

    Uint8* keystates;
    bool quitp;
    static InputHandler* s_instance;
};

#endif
