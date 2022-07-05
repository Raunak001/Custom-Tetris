#pragma once
#include "gameplay.h"
#include <map>


/*
* Texture class: loads and renders textures to screen
*/
class Texture {
public:

    /*
    * Loads texture from input file to gameRenderer
    * @return loaded texture
    */
    static SDL_Texture* loadTexture(const char *file);

    /*
    * Draws texture to screen
    */
    static void draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect);
};