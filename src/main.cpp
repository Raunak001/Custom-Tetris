/**
 * @file main.cpp
 */

#include "screen.h"
#include "gameplay.h"
#include "gameover.h"
#include <iostream>

int main(int argc, char* args[])
{
	Screen screen;
	Gameplay game;
	GameOver gameOver;

	int screenWidth = 512;
	int screenHeight = 640;

	const int FPS = 60;
	const int frameDelay = 1000/FPS;
	Uint32 frameStart;
	int frameTime;

	screen.init("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, false);
	while(Screen::screenRunning) {
		switch (Screen::currentScreen) {
			case 1:
				frameStart = SDL_GetTicks();

				game.handleEvents();
				game.update();
				game.render();

				frameTime = SDL_GetTicks() - frameStart;
				if(frameDelay > frameTime)
					SDL_Delay(frameDelay - frameTime);

				break;
			case 2:
				gameOver.handleEvents();
				game.update();
				game.render();

				break;

		}
	}
	screen.close();

	return 0;
}