#pragma once
#include "gameplay.h"

/*
*
*/
class Tetromino {
public:

    /*
    *
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
    *
    */
    static piece pieces[7];

    /*
    *
    */
    static bool active;

    /*
    *
    */
    static void updatePiece(piece* p);

    /*
    *
    */
    static void draw(piece* p, piece* p2);

    /*
    *
    */
    static bool collision(piece* p, int i);
};