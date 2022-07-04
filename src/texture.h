#pragma once
#include "gameplay.h"
#include <map>


/*
*
*/
class Texture {
public:

    /*
    *
    */
    static SDL_Texture* loadTexture(const char *file);

    /*
    *
    */
    static void draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect);
};