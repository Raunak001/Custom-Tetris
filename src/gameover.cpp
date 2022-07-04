#include "gameover.h"
#include "gameMap.h"
#include "score.h"
#include "texture.h"

SDL_Texture* GameOver::gameover = NULL;

GameOver::GameOver() {
    gameover = Texture::loadTexture("textures/gameover.png");

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 256;
    srcRect.h = 192;

    destRect.x = 32*4;
    destRect.y = 32;
    destRect.w = 256;
    destRect.h = 192;
}

GameOver::~GameOver() {
    SDL_DestroyTexture(gameover);
    gameover = nullptr;
}

void GameOver::handleEvents() {
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type) {
        case SDL_QUIT:
            screenRunning = false;
            break;
        case SDL_KEYDOWN:
            switch(e.key.keysym.sym) {
                case SDLK_r:
                    GameMap::clearMap();
                    Score::reset();
                    Gameplay::gameActive = true;
                    Screen::currentScreen = 1;
                    break;
                case SDLK_q:
                    Score::reset();
                    screenRunning = false;
                    break;
            }
            break;
        default:
            break;
    }
}

void GameOver::render() {
    Texture::draw(gameover, srcRect, destRect);
}