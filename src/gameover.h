#pragma once
#include "screen.h"

/*
* GameOver class: child class of Screen, creates 'GAME OVER!' screen and handles i/o on that screen
*/
class GameOver : public Screen{
public:

    /*
    * Initializes texture and variables
    */
    GameOver();

    /*
    * Destorys texture
    */
    ~GameOver();

    /*
    * Inherited function
    * Checks keyboard input and handles events accordingly
    */
    void handleEvents();

    /*
    * Inherited function
    * Renders gameover texture to screen
    */
    void render();

private:

    /*
    * Texture containing gameover image
    */
    static SDL_Texture* gameover;

    /*
    * Source rectangle for texture
    */
    SDL_Rect srcRect;

    /*
    * Destination rectangle for texture
    */
    SDL_Rect destRect;
};