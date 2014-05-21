#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Sprite.h"
#include "Character.h"
#include <SDL2/SDL.h>

Game* game = 0;

int main(int argc, char* argv[]) {
    game = new Game();
    // TextureManager* textureManager = TextureManager::Instance();
    InputHandler* inputHandler = InputHandler::Instance();

    // game->init("Jetpack", 100, 100, 1920, 1080, SDL_WINDOW_FULLSCREEN);
    game->init("Jetpack", 100, 100, 640, 480, 0);

    game->addGameObject(new Character(game->getRenderer()));

    while (!inputHandler->shouldQuit()
           && !inputHandler->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        inputHandler->update();
        game->update();
        game->render();
    }
    game->clean();

    return 0;
}
