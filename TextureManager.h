#ifndef __TextureManager__
#define __TextureManager__

#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_Image.h>
#include <string>
#include <map>

struct texture_t {
    SDL_Texture* sdl_texture;
    SDL_Renderer* renderer;
};

class TextureManager
{
public:
    bool load(std::string fileName, std::string id, SDL_Renderer* renderer);
    void draw(std::string id, int x, int y, int width, int height);
    void drawFrame(std::string id, int x, int y, int width, int height, int row,
                   int frame);
    static TextureManager* Instance();

private:
    TextureManager() {}
    std::map<std::string, texture_t> textureMap;
    static TextureManager* s_instance;
};

#endif
