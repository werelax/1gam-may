#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Sprite.h"
#include "Character.h"
#include "Wall.h"
#include "Config.h"
#include <SDL2/SDL.h>

Game* game = 0;

int main(int argc, char* argv[]) {

    Config* config = new Config("./config.json");
    std::cout << config->getOptionAsString("test.some.nested.value") << std::endl;

    game = new Game();
    InputHandler* inputHandler = InputHandler::Instance();

    // game->init("Jetpack", 100, 100, 1920, 1080, SDL_WINDOW_FULLSCREEN);
    game->init("Jetpack", 100, 100, 640, 480, 0);

    game->addGameObject(new Character(game->getRenderer()));

    // TODO: Read this from a map
    // TODO: Give the walls a texture or something!
    game->addGameObject(new Wall(100, 100, 100, 30));
    game->addGameObject(new Wall(400, 300, 30, 300));
    game->addGameObject(new Wall(150, 200, 200, 50));
    game->addGameObject(new Wall(0, 450, 640, 30));

    while (!inputHandler->shouldQuit()
           && !inputHandler->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        inputHandler->update();
        game->update();
        game->render();
    }
    game->clean();

    std::cout << "I'm going out cleanly..." << std::endl;

    return 0;
}
