# Tetris
## Description of Project
A revamped remake of the retro puzzle game 'Tetris' using C++ and SDL2, a multimedia library. The objective of the game is to score the most points possible before the game pieces reach the top of the board. Players score points by filling a row with pieces. The more rows cleared at once, the more points. There is a level progression system that goes to level 10, and each level increases the speed of the tetris pieces falling. Can you beat my highscore of 28,528? <br>
![Screenshot](textures/Tetris.png)

## Description of File Interaction
The `Screen` class is a parent class for its 2 children classes, `Gameplay` and `GameOver`. It instantiates a window through SDL2 libraries and defines some virtual functions for the children to inherit. The `Tetromino` class, `GameMap` class, and `Score` class all interact with the `Gameplay` class to render what is seen as the gameplay on the screen. The `Tetromino` class defines 7 separate Tetris tetrominos (Tetris pieces) inside of a 2D array, and each tetromino is stored by a public struct. The `GameMap` class initializes an empty map with a 2D array and loads those positions on the screen with a customized texture `textures/background.png`. It also constantly checks where the current tetromino piece is on the board and verifies valid moves and when to call the next tetromino. The `Score` class updates the game's scoring system everytime a piece "lands" on the grid. The `GameMap` class also interacts with the `GameOver` class when the game reaches the conditions to fail. There is also a global `Texture` class that simplifies loading and rendering custom `png` files for each position of the screen. Finally, `main.cpp` defines objects of `Screen`, `Gameplay`, and `GameOver`, sets a base frame rate, and handles inputs from the user.

## How to Execute
### On MacOS
Make sure you have SDL2 and SDL2_Image libraries installed. If not install them via brew in the terminal by typing `brew install SDL2` and `brew install SDL2_image` <br>
Run the contents of `main.cpp` with `make` in the terminal followed by `./main`. If the `make` command does not register, run the full Makefile command `g++ src/main.cpp src/screen.cpp src/gameover.cpp src/gameplay.cpp src/texture.cpp src/gameMap.cpp src/tetromino.cpp src/score.cpp -o main -I include -L lib -l SDL2-2.0.0 -l SDL2_image-2.0.0`
### On Windows
Run the command `g++ src/main.cpp src/screen.cpp src/gameover.cpp src/gameplay.cpp src/texture.cpp src/gameMap.cpp src/tetromino.cpp src/score.cpp -o main -I includeWindows -L libWindows -l SDL2 -l SDL2_image` in the command prompt followed by `./main` or `./main.exe`

## Controls
Left: Move piece left <br>
Right: Move piece right <br>
Up: Rotate piece clockwise <br>
Down: Move piece down <br>
Space Bar: Quick drop piece <br>

Q: Quit <br>
R: Retry <br>
