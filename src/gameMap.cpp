#include "gameMap.h"
#include "texture.h"
#include "tetromino.h"
#include "gameplay.h"
#include "score.h"

int GameMap::map[20][10] =  {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}};

int GameMap::nextPiece[20][6] = {
    {9, 9, 9, 9, 9, 9},
    {9, 0, 0, 0, 0, 9},
    {9, 0, 0, 0, 0, 9},
    {9, 0, 0, 0, 0, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9}};

GameMap::GameMap() {
    background = Texture::loadTexture("textures/background.png");
    border = Texture::loadTexture("textures/border.png");

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 32;
    srcRect.h = 32;

    destRect.x = 0;
    destRect.y = 0;
    destRect.w = 32;
    destRect.h = 32;

    borderRect.x = 0;
    borderRect.y = 0;
    borderRect.w = 32;
    borderRect.h = 32;
}

GameMap::~GameMap() {
    SDL_DestroyTexture(background);
    background = nullptr;
    SDL_DestroyTexture(border);
    border = nullptr;
}

void GameMap::renderMap() {
    checkLine();
    int temp = 0;
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 10; j++) {
            temp = map[i][j];
            destRect.x = j*32;
            destRect.y = i*32;
            if(temp > 0) {
                if(SDL_SetRenderDrawColor(Gameplay::gameRenderer, Tetromino::pieces[temp-1].color.r, Tetromino::pieces[temp-1].color.g, Tetromino::pieces[temp-1].color.b, 255) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
                if(SDL_RenderFillRect(Gameplay::gameRenderer, &destRect) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
                if(SDL_SetRenderDrawColor(Gameplay::gameRenderer, 0, 0, 0, 255) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
                if(SDL_RenderDrawRect(Gameplay::gameRenderer, &destRect) < 0)
                    std::cout << "Could not load piece! Error: " << SDL_GetError() << std::endl;
            } else {
                Texture::draw(background, srcRect, destRect);
            }
        }
    }
}

void GameMap::renderNextPieceMap() {
    int temp = 0;
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 6; j++) {
            temp = nextPiece[i][j];
            borderRect.x = 10*32 + j*32;
            borderRect.y = i*32;
            switch(temp) {
                case 0:
                    Texture::draw(background, srcRect, borderRect);
                    break;
                case 9:
                    Texture::draw(border, srcRect, borderRect);
                    break;
            }
        }
    }
}

void GameMap::clearMap() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 10; j++) {
            map[i][j] = 0;
        }
    }
}

void GameMap::updateLanded(Tetromino::piece* p) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(p->arr[i][j] == 1) {
                p->rect.x =  p->dstRectX * 32 + j * 32;
                p->rect.y =  p->dstRectY * 32 + i * 32;
                map[p->rect.y/32-1][p->rect.x/32] = p->identifier;
            }
        }
    }
    Score::score += 2;
}

bool GameMap::checkCollision(Tetromino::piece* p) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(p->arr[i][j] == 1) {
                p->rect.x =  p->dstRectX * 32 + j * 32;
                p->rect.y =  p->dstRectY * 32 + i * 32;
                if(map[p->rect.y/32][p->rect.x/32] != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool GameMap::checkGameOver(Tetromino::piece* p) {
    if(p->topmost < 0)
        return false;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
                if(map[p->rect.y/32][p->rect.x/32] != 0) {
                    return false;
                }
        }
    }
    return true;
}


/*
* Helper function for space(Tetromino::piece* p), obtains lowest tetromino index in p->arr[4][4]
*/
int lowestIndex(Tetromino::piece* p) {
    for(int i = (p->rotationBox - 1); i >= 0; i--) {
        for(int j = 0; j < p->rotationBox; j++) {
            if(p->arr[i][j] > 0)
                return i;
        }
    }
    return 0;
}

void GameMap::space(Tetromino::piece* p) {
    for(int i = p->downmost/32 + 1; i < 20; i++) {
        for(int j = p->dstRectX; j <= p->dstRectX + p->rotationBox - 1; j++) {
            if(map[i][j] > 0) {
                int count = 0;
                for(int m = lowestIndex(p); m >= 0; m--) {
                    for(int k = p->dstRectX; k <= p->dstRectX + p->rotationBox - 1; k++) {
                        if(p->arr[m][k - p->dstRectX] > 0 && map[i][k] > 0) {
                            p->dstRectY += i - p->downmost/32 + count;
                            goto end;
                        }
                    }
                    count++;
                }
            }
        }
    }
    p->dstRectY += 20 - p->downmost/32;
    end: {}
}

void GameMap::checkLine() {
    int lines = 0;
    for(int i = 0; i < 20; i++) {
        int row = 0;
        for(int j = 0; j < 10; j++) {
            if(map[i][j] != 0)
                row++;
        }
        if(row == 10) {
            for(int k = 0; k < 10; k++) {
                map[i][k] = 0;
            }
            lines++;
            pushRow(i);
        }
    }
    switch(lines) {
        case 1:
            Score::score += 40 * Score::level;
            break;
         case 2:
            Score::score += 100 * Score::level;
            break;
         case 3:
            Score::score += 300 * Score::level;
            break;
         case 4:
            Score::score += 1200 * Score::level;
            break;
        default:
            break;
    }
    Score::lines += lines;
    Score::updateLevel();
    Score::updateSpeed();
    
    
}

void GameMap::pushRow(int x) {
    for(int i = x; i > 0; i--) {
        for(int j = 0; j < 10; j++) {
            map[i][j] = map[i-1][j];
        }
    }
    for(int j = 0; j < 10; j++) {
        map[0][j] = 0;
    }
}