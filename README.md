# Tetris
## Description of Project

## How to execute
### On MacOS
Run the contents of `main.cpp` with `make` in the terminal followed by `./main`. If the `make` command does not register, run the full Makefile command `g++ src/main.cpp src/screen.cpp src/gameover.cpp src/gameplay.cpp src/texture.cpp src/gameMap.cpp src/tetromino.cpp src/score.cpp -o main -I include -L lib -l SDL2-2.0.0 -l SDL2_image-2.0.0`

### On Windows
Run the command `g++ src/main.cpp src/screen.cpp src/gameover.cpp src/gameplay.cpp src/texture.cpp src/gameMap.cpp src/tetromino.cpp src/score.cpp -o main -I includeWindows -L libWindows -l SDL2 -l SDL2_image` in the terminal followed by `./main` or `./main.exe`

## Controls
Left: Move piece left
Right: Move piece right
Up: Rotate piece clockwise once
Down: Move piece down
Space Bar: Quick drop piece

Q: Quit
R: Retry
