#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

/*
* Screen Class: parent class for handling i/o devices, updating game mechanics, and rendering
* textures/sprites to screen 
*/
class Screen {
protected:
    
    /*
    * Virtual function for child classes
    */
    virtual void handleEvents();

    /*
    * Virtual function for child classes
    */
    virtual void update();

    /*
    * Virtual function for child classes
    */
    virtual void render();

    /*
    * Game window
    */
    static SDL_Window* window;

public:
    /*
    * Initializes SDL, game window, and renderer
    */
    void init(const char* title, int x, int y, int w, int h, bool fs);

    /*
    * Closes game window and renderer
    */
    void close();

    /*
    * Game renderer
    */
    static SDL_Renderer* gameRenderer;

    /*
    * Set to 1 if game is running and 2 else
    */
    static int currentScreen;

    /*
    * Set to true if window screen is active
    */
    static bool screenRunning;
};