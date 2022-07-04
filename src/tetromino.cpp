#include "tetromino.h"
#include "gameMap.h"
#include "screen.h"

Tetromino::piece Tetromino::pieces[7] = {{
    {{1, 1, 1, 1}, //I piece
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}}, {3, 190, 252}, 3, 0, {0, 0, 32, 32}, 4, 0, 0, 0, 0, 1
}, {
    {{1, 1, 0, 0}, //O piece
    {1, 1, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}}, {223, 255, 43}, 4, 0, {0, 0, 32, 32}, 2, 0, 0, 0, 0, 2
}, {
    {{1, 1, 1, 0}, //T piece
    {0, 1, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}}, {248, 43, 255}, 3, 0, {0, 0, 32, 32}, 3, 0, 0, 0, 0, 3
}, {
    {{0, 1, 0, 0}, //J piece
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0}}, {28, 28, 212}, 4, 0, {0, 0, 32, 32}, 3, 0, 0, 0, 0, 4
}, {
    {{1, 0, 0, 0}, //L piece
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0}}, {212, 89, 28}, 4, 0, {0, 0, 32, 32}, 3, 0, 0, 0, 0, 5
}, {
    {{0, 1, 1, 0}, //S piece
    {1, 1, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}}, {46, 212, 28}, 4, 0, {0, 0, 32, 32}, 3, 0, 0, 0, 0, 6
}, {
    {{1, 1, 0, 0}, //Z piece
    {0, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}}, {212, 46, 28}, 4, 0, {0, 0, 32, 32}, 3, 0, 0, 0, 0, 7
}};
bool Tetromino::active = true;

void leftMost(Tetromino::piece* p) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(p->arr[j][i] == 1) {
                p->leftmost = p->dstRectX * 32 + i * 32;
                // std::cout << "leftmost: " << p->leftmost << std::endl;
                return;
            }
        }
    }
}

void rightMost(Tetromino::piece* p) {
    for(int i = 3; i >= 0; i--) {
        for(int j = 0; j < 4; j++) {
            if(p->arr[j][i] == 1) {
                p->rightmost = p->dstRectX * 32 + i * 32;
                // std::cout << "rightmost: " << p->rightmost << std::endl;
                return;
            }
        }
    }
}

void downMost(Tetromino::piece* p) {
    for(int i = 3; i >= 0; i--) {
        for(int j = 0; j < 4; j++) {
            if(p->arr[i][j] == 1) {
                p->downmost = p->dstRectY * 32 + i * 32;
                // std::cout << "downmost: " << p->downmost << std::endl;
                return;
            }
        }
    }
}

void topMost(Tetromino::piece* p) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(p->arr[i][j] == 1) {
                p->topmost = p->dstRectY * 32 + i * 32;
                // std::cout << "topmost: " << p->topmost << std::endl;
                return;
            }
        }
    }
}

void rotate(Tetromino::piece *p) {
    int pieceSize = p->rotationBox;
    for(int i = 0; i < 2; i++) {
        for(int j = i; j < pieceSize-i-1; j++) {
            int temp = p->arr[i][j];
            p->arr[i][j] = p->arr[pieceSize-j-1][i];
            p->arr[pieceSize-j-1][i] = p->arr[pieceSize-i-1][pieceSize-j-1];
            p->arr[pieceSize-i-1][pieceSize-j-1] = p->arr[j][pieceSize-i-1];
            p->arr[j][pieceSize-i-1] = temp;
        }
    }
}

void checkRotate(Tetromino::piece* p) {
    rotate(p);
    leftMost(p);
    rightMost(p);
    downMost(p);
    topMost(p);
    if(p->leftmost < 0) {
        p->dstRectX += -(p->leftmost)/32;
    }
    if(p->rightmost > 32*9) {
        p->dstRectX -= (p->rightmost-32*9)/32;
    }
    if(p->downmost > 32*19) {
        p->dstRectY -= (p->downmost-32*19)/32;
    }
    if(!GameMap::checkCollision(p)) {
        rotate(p);
        rotate(p);
        rotate(p);
    }
}

void Tetromino::updatePiece(piece *p) {
    if(Gameplay::left) {
        p->dstRectX--;
        if(!collision(p, 0) || !GameMap::checkCollision(p))
            p->dstRectX++;
        Gameplay::left = false;
    }
    if(Gameplay::right) {
        p->dstRectX++;
        if(!collision(p, 1) || !GameMap::checkCollision(p))
            p->dstRectX--;
        Gameplay::right = false;
    }
    if(Gameplay::down) {
        p->dstRectY++;
        if(!collision(p, 2))
            p->dstRectY--;
        Gameplay::down = false;
    }
    if(Gameplay::up) {
        checkRotate(p);
        Gameplay::up = false;
    }
    if(Gameplay::space) {
        GameMap::space(p);
        GameMap::updateLanded(p);
        active = false;
        Gameplay::space = false;
    }
}

void Tetromino::draw(piece* p, piece* p2) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(p->arr[i][j] == 1) {
                p->rect.x =  p->dstRectX * 32 + j * 32;
                p->rect.y =  p->dstRectY * 32 + i * 32;
                if(!GameMap::checkGameOver(p)) {
                    Screen::currentScreen = 2;
                    Gameplay::gameActive = false;
                    active = false;
                    goto end;
                }
                if(SDL_SetRenderDrawColor(Screen::gameRenderer, p->color.r, p->color.g, p->color.b, 255) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
                if(SDL_RenderFillRect(Screen::gameRenderer, &p->rect) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
                if(SDL_SetRenderDrawColor(Screen::gameRenderer, 0, 0, 0, 255) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
                if(SDL_RenderDrawRect(Screen::gameRenderer, &p->rect) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
            }
            if(p2->arr[i][j] == 1) {
                p2->rect.x =  p2->dstRectX * 32 + j * 32 + 8*32;
                p2->rect.y =  p2->dstRectY * 32 + i * 32 + 32;

                if(SDL_SetRenderDrawColor(Screen::gameRenderer, p2->color.r, p2->color.g, p2->color.b, 255) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
                if(SDL_RenderFillRect(Screen::gameRenderer, &p2->rect) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
                if(SDL_SetRenderDrawColor(Screen::gameRenderer, 0, 0, 0, 255) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
                if(SDL_RenderDrawRect(Screen::gameRenderer, &p2->rect) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
            }
        }
    }
    leftMost(p);
    rightMost(p);
    downMost(p);
    topMost(p);
    end: {}
}

bool Tetromino::collision(piece* p, int i) {
    bool value = true;
    if(p->leftmost <= 0 && i == 0)
        value = false;
    if(p->rightmost >= 32*9 && i == 1)
        value = false;
    if(p->downmost >= 32*19 && i == 2) {
        GameMap::updateLanded(p);
        active = false;
        value = false;
    }
    if(!GameMap::checkCollision(p) && i == 2) {
        GameMap::updateLanded(p);
        active = false;
        value = false;
    }
    return value;
}