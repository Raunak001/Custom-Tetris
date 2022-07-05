#pragma once
#include "gameplay.h"

/*
* Tetromino class: creates and handles tetromnino objects (tetris pieces)
*/
class Tetromino {
public:

    /*
    * piece struct: contains unique shapes, variables, and identifiers for objects
    */
    struct piece {
        int arr[4][4];
        SDL_Color color;
        int dstRectX;
        int dstRectY;
        SDL_Rect rect;
        int rotationBox;
        int leftmost;
        int rightmost;
        int downmost;
        int topmost;
        int identifier;
    };

    /*
    * Contains each of the 7 classic tetromino pieces
    */
    static piece pieces[7];

    /*
    * Set to true if current piece is falling
    */
    static bool active;

    /*
    * Updates current tetromino's position based on keyboard input
    */
    static void updatePiece(piece* p);

    /*
    * Draws current tetromino's location to gameboard
    */
    static void draw(piece* p, piece* p2);

    /*
    * Checks if current tetromino collides with any other pieces / borders
    * @return false if there is a collision
    */
    static bool collision(piece* p, int i);
};