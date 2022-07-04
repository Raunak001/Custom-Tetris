#include <cstdlib>
#include <ctime>
#include "screen.h"
#include "gameplay.h"
#include "gameover.h"
#include "texture.h"
#include "gameMap.h"
#include "tetromino.h"

using namespace std;

SDL_Renderer* Screen::gameRenderer = nullptr;
SDL_Window* Screen::window = nullptr;
bool Screen::screenRunning = true;
int Screen::currentScreen = 1;

void Screen::handleEvents() {}

void Screen::update() {}

void Screen::render() {}

void Screen::init(const char* title, int x, int y, int w, int h, bool fs) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "SDL could not initialize! Error: " << SDL_GetError() << endl;
    } else {
        Uint32 flags = 0;
        if(fs) {flags = SDL_WINDOW_FULLSCREEN;}
        window = SDL_CreateWindow(title, x, y, w, h, 0);
        if(window == NULL) {
            cout << "Window could not be created! Error: " << SDL_GetError() << endl;
        } else {
            gameRenderer = SDL_CreateRenderer(Screen::window, -1, 0);
            if(gameRenderer == NULL) {
                std::cout << "Game could not render! Error: " << SDL_GetError() << std::endl;
            } else {
                SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 255);
                Gameplay::init();
            }
        }
    }
}

void Screen::close() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(gameRenderer);
    SDL_Quit();
}