#include "Game.h"
#include "Sprite.h"

Game* game = 0;

int main(int argc, char* argv[]) {
    game = new Game();
    // game->init("Jetpack", 100, 100, 1920, 1080, SDL_WINDOW_FULLSCREEN);

    game->init("Jetpack", 100, 100, 640, 480, 0);

    // game->addSprite(new Sprite("sprites.png", 0, 0, 51, 100, 12,
    //                            game->getRenderer()));
    // game->addSprite(new Sprite("chunli.png", 100, 100, 80, 156, 6,
    //                            game->getRenderer()));

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }
    game->clean();

    return 0;
}
