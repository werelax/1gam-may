#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Sprite.h"
#include "Character.h"
#include <SDL2/SDL.h>

Game* game = 0;

int main(int argc, char* argv[]) {
    game = new Game();
    InputHandler* inputHandler = InputHandler::Instance();

    // game->init("Jetpack", 100, 100, 1920, 1080, SDL_WINDOW_FULLSCREEN);
    game->init("Jetpack", 100, 100, 640, 480, 0);

    game->addGameObject(new Character(game->getRenderer()));
    // TODO: Map -> list of walls? readed from a level.map?
    // Maybe I should just bite the bullet and do some nice tiling?
    // But then: how to check collisions? Solid tiles (i like this one)?
    // Or maybe different tile z-levels, like some collisionable, fg, bg, etc..
    // game->addGameObjectList(new GameMap("level.map"));

    while (!inputHandler->shouldQuit()
           && !inputHandler->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        inputHandler->update();
        game->update();
        game->render();
    }
    game->clean();

    return 0;
}
