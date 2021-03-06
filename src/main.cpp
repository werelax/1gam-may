#include "Game.hpp"
#include "TextureManager.hpp"
#include "InputHandler.hpp"
#include "Sprite.hpp"
#include "Character.hpp"
#include "Wall.hpp"
#include "Config.hpp"
#include <SDL2/SDL.h>

Game* game = 0;

int main(int argc, char* argv[]) {

    Config* config = new Config("./config.json");

    game = new Game();
    InputHandler* inputHandler = InputHandler::Instance();

    // game->init("Jetpack", 100, 100, 1920, 1080, SDL_WINDOW_FULLSCREEN);
    game->init("Jetpack", 100, 100, 640, 480, 0);

    game->addCharacter(new Character(game->getRenderer()));

    std::list<Wall*> walls = config->getWallList("walls");
    for_each(walls.begin(), walls.end(), [&] (Wall* wall) {
        game->addGameObject(wall);
    });

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
