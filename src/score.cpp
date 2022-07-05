#include "score.h"
#include "texture.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int Score::score = 0;
int Score::highscore = score;
int Score::lines = 0;
int Score::level = 1;
int Score::tetrominoSpeed = 0;

Score::Number Score::numbers[10] = {{
        0, {0, 0, 15, 26}, NULL
    }, {
        1, {0, 0, 15, 26}, NULL
    }, {
        2, {0, 0, 15, 26}, NULL
    }, {
        3, {0, 0, 15, 26}, NULL
    }, {
        4, {0, 0, 15, 26}, NULL
    }, {
        5, {0, 0, 15, 26}, NULL
    }, {
        6, {0, 0, 15, 26}, NULL
    }, {
        7, {0, 0, 15, 26}, NULL
    }, {
        8, {0, 0, 15, 26}, NULL
    }, {
        9, {0, 0, 15, 26}, NULL
}};

Score::Score() {
    scoreboardText = Texture::loadTexture("textures/scoreboard.png");

    numbers[0].texture =  Texture::loadTexture("textures/0.png");
    numbers[1].texture =  Texture::loadTexture("textures/1.png");
    numbers[2].texture =  Texture::loadTexture("textures/2.png");
    numbers[3].texture =  Texture::loadTexture("textures/3.png");
    numbers[4].texture =  Texture::loadTexture("textures/4.png");
    numbers[5].texture =  Texture::loadTexture("textures/5.png");
    numbers[6].texture =  Texture::loadTexture("textures/6.png");
    numbers[7].texture =  Texture::loadTexture("textures/7.png");
    numbers[8].texture =  Texture::loadTexture("textures/8.png");
    numbers[9].texture =  Texture::loadTexture("textures/9.png");

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 32;
    srcRect.h = 32;

    scoreboardRect.x = 32*11;
    scoreboardRect.y = 32*6;
    scoreboardRect.w = 128;
    scoreboardRect.h = 256;

    std::ifstream file;
    std::stringstream sstream;
    std::string firstLine;
    std::string temp;
    file.open("src/highscore.txt");
    if(file.is_open()) {
        while(getline(file, firstLine)) {
            sstream << firstLine;
            sstream >> temp;
            highscore = stoi(temp);
            sstream.clear();
        }
        file.close();
    }
}

Score::~Score() {
    SDL_DestroyTexture(scoreboardText);
    scoreboardText = nullptr;
    SDL_DestroyTexture(numbers[0].texture);
    numbers[0].texture = nullptr;
    SDL_DestroyTexture(numbers[1].texture);
    numbers[1].texture = nullptr;
    SDL_DestroyTexture(numbers[2].texture);
    numbers[2].texture = nullptr;
    SDL_DestroyTexture(numbers[3].texture);
    numbers[3].texture = nullptr;
    SDL_DestroyTexture(numbers[4].texture);
    numbers[4].texture = nullptr;
    SDL_DestroyTexture(numbers[5].texture);
    numbers[5].texture = nullptr;
    SDL_DestroyTexture(numbers[6].texture);
    numbers[6].texture = nullptr;
    SDL_DestroyTexture(numbers[7].texture);
    numbers[7].texture = nullptr;
    SDL_DestroyTexture(numbers[8].texture);
    numbers[8].texture = nullptr;
    SDL_DestroyTexture(numbers[9].texture);
    numbers[9].texture = nullptr;
}

void Score::updateLevel() {
    level = lines / 10 + 1;
    if (level > 10)
        level = 10;
}

void Score::updateSpeed() {
    tetrominoSpeed = level * 80;
}

void Score::reset() {
    if(score > highscore) {
        highscore = score;

        std::ofstream tempFile;
        tempFile.open("src/temp.txt");
        tempFile << std::to_string(highscore);
        tempFile.close();
        remove("src/highscore.txt");
        rename("src/temp.txt", "src/highscore.txt");
    }
    score = 0;
    lines = 0;
    level = 1;
    tetrominoSpeed = 0;
}

void Score::convertScore() {
    if(score > 9999999)
        score = 9999999;
    std::string textScore = std::to_string(score);
    std::string leadingZeros = "";
    for(int i = 0; i < 7 - textScore.size(); i++) {
        leadingZeros += "0";
    }
    leadingZeros += textScore;
    for(int i = 0; i < 7; i++) {
        int num = leadingZeros[i] - '0';
        numbers[num].numRect.x = 32*11 + 9 + 16*i;
        numbers[num].numRect.y = 32*7 + 4;
        Texture::draw(numbers[num].texture, srcRect, numbers[num].numRect);
    }
}

void Score::convertHighscore() {
    std::string textScore = std::to_string(highscore);
    std::string leadingZeros = "";
    for(int i = 0; i < 7 - textScore.size(); i++) {
        leadingZeros += "0";
    }
    leadingZeros += textScore;
    for(int i = 0; i < 7; i++) {
        int num = leadingZeros[i] - '0';
        numbers[num].numRect.x = 32*11 + 9 + 16*i;
        numbers[num].numRect.y = 32*7 + 68;
        Texture::draw(numbers[num].texture, srcRect, numbers[num].numRect);
    }
}

void Score::convertLines() {
    if(lines > 9999999)
        lines = 9999999;
    std::string textScore = std::to_string(lines);
    std::string leadingZeros = "";
    for(int i = 0; i < 7 - textScore.size(); i++) {
        leadingZeros += "0";
    }
    leadingZeros += textScore;
    for(int i = 0; i < 7; i++) {
        int num = leadingZeros[i] - '0';
        numbers[num].numRect.x = 32*11 + 9 + 16*i;
        numbers[num].numRect.y = 32*7 + 132;
        Texture::draw(numbers[num].texture, srcRect, numbers[num].numRect);
    }
}

void Score::convertLevel() {
    std::string textScore = std::to_string(level);
    std::string leadingZeros = "";
    for(int i = 0; i < 2 - textScore.size(); i++) {
        leadingZeros += "0";
    }
    leadingZeros += textScore;
    for(int i = 0; i < 2; i++) {
        int num = leadingZeros[i] - '0';
        numbers[num].numRect.x = 32*11 + 50 + 16*i;
        numbers[num].numRect.y = 32*7 + 196;
        Texture::draw(numbers[num].texture, srcRect, numbers[num].numRect);
    }
}

void Score::renderScore() {
    Texture::draw(scoreboardText, srcRect, scoreboardRect);
    convertScore();
    convertHighscore();
    convertLines();
    convertLevel();
}