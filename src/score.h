#pragma once
#include "gameplay.h"

/*
* Score class: keeps track of gameboard logistics (score, highscore, lines, and level)
*/
class Score {
public:

    /*
    * Initializes textures and variables, reads from 'highscore.txt' file to obtain local highscore
    */
    Score();

    /*
    * Destroys textures
    */
    ~Score();

    /*
    * Number struct: contains unique identifiers/textures for each object
    */
    struct Number {
        int num;
        SDL_Rect numRect;
        SDL_Texture* texture;
    };

    /*
    * Updates current level based off of lines cleared, does not exceed 10
    */
    static void updateLevel();

    /*
    * Updates tetromino falling speed at a rate of 80ms faster per level
    */
    static void updateSpeed();

    /*
    * Resets scoreboard and stores highscore into 'highscore.txt' file
    */
    static void reset();

    /*
    * Adds leading 0's to score and draws corresponding number textures to scoreboard
    */
    void convertScore();

    /*
    * Adds leading 0's to highscore and draws corresponding number textures to scoreboard
    */
    void convertHighscore();

    /*
    * Adds leading 0's to lines and draws corresponding number textures to scoreboard
    */
    void convertLines();

    /*
    * Adds leading 0's to level and draws corresponding number textures to scoreboard
    */
    void convertLevel();

    /*
    * Renders textures to screen
    */
    void renderScore();

    /*
    * Stores current game score
    */
    static int score;

    /*
    * Stores local highest score
    */
    static int highscore;

    /*
    * Stores current game lines cleared
    */
    static int lines;

    /*
    * Stores current game's level
    */
    static int level;

    /*
    * Stores current game's tetromino falling speed
    */
    static int tetrominoSpeed;

private:

    /*
    * Stores Number struct of numbers [0, 9]
    */
    static Number numbers[10];

    /*
    * Source rectangle
    */
    SDL_Rect srcRect;

    /*
    * Scoreboard destination rectangle
    */
    SDL_Rect scoreboardRect;

    /*
    * Scoreboard texture
    */
    SDL_Texture* scoreboardText;
};