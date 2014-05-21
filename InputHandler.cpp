#include "InputHandler.h"

InputHandler* InputHandler::Instance() {
    if (s_instance == 0) {
        s_instance = new InputHandler();
    }
    return s_instance;
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
    if (keystates != 0) {
        return keystates[key] == 1;
    } else {
        return false;
    }
}

bool InputHandler::shouldQuit() {
    return quitp;
}

void InputHandler::onKeyDown() {
    keystates = (Uint8*) SDL_GetKeyboardState(NULL);
}

void InputHandler::onKeyUp() {
    keystates = (Uint8*) SDL_GetKeyboardState(NULL);
}

void InputHandler::update() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            quitp = true;
            break;
        case SDL_KEYDOWN:
            onKeyDown();
        case SDL_KEYUP:
            onKeyUp();
        default:
            break;
        }
    }
}

InputHandler* InputHandler::s_instance = 0;
