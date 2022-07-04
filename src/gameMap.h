#pragma once
#include "gameplay.h"
#include "tetromino.h"

/*
* GameMap class: create background texture and handle collisions with tetrominos
*/
class GameMap {
public:

    /*
    * Initializes textures and variables
    */
    GameMap();

    /*
    * Destorys textures to free memory
    */
    ~GameMap();

    /*
    * Renders background map tiles as well as landed tetrominos
    */
    void renderMap();

    /*
    * Renders right side map tiles and next tetromino piece
    */
    void renderNextPieceMap();

    /*
    * Resets map to blank state for replaying purposes
    */
    static void clearMap();

    /*
    * Updates landed tetrominos in map[20][10] array with specific values assigned to differentiating tetrominos
    * Also increments score by 2
    */
    static void updateLanded(Tetromino::piece* p);

    /*
    * Verifies if tetromino can move in directional slot by checking occupied spaces in map[20][10]
    * @return false if tetromino cannot move in specified direction
    */
    static bool checkCollision(Tetromino::piece* p);

    /*
    * Verifies if tetromino piece has reached the top of the game board or a new piece cannot be instantiated
    * @return false if game over
    */
    static bool checkGameOver(Tetromino::piece* p);

    /*
    * Places tetromino in next valid spot if 'space bar' is pressed
    */
    static void space(Tetromino::piece* p);
    
    /*
    * Checks if row in map[20][10] is filled with tetromino
    * - Clears lines, pushes all tetrominos above line down, and inserts blank row above if row is filled
    */
    void checkLine();

    /*
    * Helper function for checkLine(), pushes all tetrominos above specified index down
    */
    void pushRow(int x);

private:

    /*
    * Source rectangle for textures
    */
    SDL_Rect srcRect;

    /*
    * Destination rectangle for background texture
    */
    SDL_Rect destRect;

    /*
    * Destination rectangle for border texture
    */
    SDL_Rect borderRect;

    /*
    * Array containing values of background and tetromino pieces, initialized to all background textures
    */
    static int map[20][10];

    /*
    * Array containing values of border, background, and next tetromino pieces, initialized to border and background textures
    */
    static int nextPiece[20][6];

    /*
    * Texture containing background image
    */
    SDL_Texture* background;

    /*
    * Texture containing border image
    */
    SDL_Texture* border;
};