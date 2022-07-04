#include "texture.h"

SDL_Texture* Texture::loadTexture(const char *file) {
    SDL_Surface* temp = IMG_Load(file);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Screen::gameRenderer, temp);
    // if(texture == NULL)
    //     std::cout << "Could not load texture! Error: " << SDL_GetError() << ", File: " << file << std::endl;
    SDL_FreeSurface(temp);

    return texture;
}

void Texture::draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect) {
    if(SDL_RenderCopy(Screen::gameRenderer, texture, NULL, &destRect) < 0) {
        std::cout << "Could not copy render texture! Error: " << SDL_GetError() << std::endl;
    }
}