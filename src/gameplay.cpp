#include <cstdlib>
#include <ctime>
#include "gameplay.h"
#include "texture.h"
#include "gameMap.h"
#include "tetromino.h"
#include "score.h"
#include "gameover.h"

Tetromino::piece piece;
Tetromino::piece nextPiece;
GameMap* gameMap;
Score* score;
GameOver* gameOver;

bool Gameplay::left = false;
bool Gameplay::right = false;
bool Gameplay::down = false;
bool Gameplay::up = false;
bool Gameplay::space = false;
bool Gameplay::gameActive = true;

Uint32 timeStart;

void Gameplay::init() {
    srand(time(0));
    for(int i = 0; i < 4; i++)
        rand();
    gameMap = new GameMap();
    score = new Score();
    gameOver = new GameOver();
    piece = Tetromino::pieces[rand()%7];
    nextPiece = Tetromino::pieces[rand()%7];

    timeStart = SDL_GetTicks();
}

void Gameplay::handleEvents() {
    if(SDL_GetTicks() - timeStart > (Uint32)(900 - Score::tetrominoSpeed)) {
        down = true;
        timeStart = SDL_GetTicks();
    }
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type) {
        case SDL_QUIT:
            screenRunning = false;
            break;
        case SDL_KEYDOWN:
            switch(e.key.keysym.sym) {
                case SDLK_LEFT:
                    left = true;
                    break;
                case SDLK_RIGHT:
                    right = true;
                    break;
                case SDLK_UP:
                    up = true;
                    break;
                case SDLK_DOWN:
                    down = true;
                    break;
                case SDLK_SPACE:
                    space = true;
                    break;
                // case SDLK_ESCAPE:
                //     screenRunning = false;
                //     break;
            }
            break;
        default:
            break;
    }
}

void Gameplay::update() {
    Tetromino::updatePiece(&piece);
}

void Gameplay::render() {
    if(!Tetromino::active && gameActive) {
        piece = nextPiece;
        nextPiece = Tetromino::pieces[rand()%7];
        Tetromino::active = true;
    }

    if(gameActive) {
        SDL_RenderClear(gameRenderer);
        gameMap->renderMap();
        gameMap->renderNextPieceMap();
        Tetromino::draw(&piece, &nextPiece);
        score->renderScore();
        SDL_RenderPresent(gameRenderer);
    }
    else {
        SDL_RenderClear(gameRenderer);
        gameMap->renderMap();
        gameMap->renderNextPieceMap();
        Tetromino::draw(&piece, &nextPiece);
        score->renderScore();
        gameOver->render();
        SDL_RenderPresent(gameRenderer);
    }
}
