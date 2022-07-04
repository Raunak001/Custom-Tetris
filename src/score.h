#pragma once
#include "gameplay.h"

/*
* Score class: keeps track of gameboard logistics (score, highscore, lines, and level)
*/
class Score {
public:

    /*
    *
    */
    Score();

    /*
    *
    */
    ~Score();

    /*
    *
    */
    struct Number {
        int num;
        SDL_Rect numRect;
        SDL_Texture* texture;
    };

    /*
    *
    */
    static void checkLevel();

    /*
    *
    */
    static void updateSpeed();

    /*
    *
    */
    static void reset();

    /*
    *
    */
    void convertScore();

    /*
    *
    */
    void convertHighscore();

    /*
    *
    */
    void convertLines();

    /*
    *
    */
    void convertLevel();

    /*
    *
    */
    void renderScore();

    /*
    *
    */
    static int score;

    /*
    *
    */
    static int highscore;

    /*
    *
    */
    static int lines;

    /*
    *
    */
    static int level;

    /*
    *
    */
    static int tetrominoSpeed;

private:

    /*
    *
    */
    static Number numbers[10];

    /*
    *
    */
    SDL_Rect srcRect;

    /*
    *
    */
    SDL_Rect scoreboardRect;

    /*
    *
    */
    SDL_Texture* scoreboardText;
};