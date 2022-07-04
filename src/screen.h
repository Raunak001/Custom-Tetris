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
    *
    */
    virtual void handleEvents();

    /*
    *
    */
    virtual void update();

    /*
    *
    */
    virtual void render();

    static SDL_Window* window;

public:
    /*
    *
    */
    void init(const char* title, int x, int y, int w, int h, bool fs);

    /*
    *
    */
    void close();

    /*
    *
    */
    static SDL_Renderer* gameRenderer;

    /*
    *
    */
    static int currentScreen;

    /*
    *
    */
    static bool screenRunning;
};