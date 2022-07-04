#pragma once
#include "screen.h"

/*
* Gameplay class: child class of Screen, creates gameplay screen and handles i/o on that screen
*/
class Gameplay : public Screen{
public:

    /*
    * Initializes game objects
    */
    static void init();

    /*
    * Inherited function
    * Checks keyboard input and handles events accordingly
    */
    void handleEvents();

    /*
    * Inherited function
    * Updates game objects
    */
    void update();

    /*
    * Inherited function
    * Renders game objects to screen
    */
    void render();

    /*
    * Set to true if 'left' key is pressed
    */
    static bool left;

    /*
    * Set to true if 'right' key is pressed
    */
    static bool right;

    /*
    * Set to true if 'up' key is pressed
    */
    static bool up;

    /*
    * Set to true if 'down' key is pressed
    */
    static bool down;

    /*
    * Set to true if 'space' key is pressed
    */
    static bool space;

    /*
    * Set to true if game is in progress
    */
    static bool gameActive;
};