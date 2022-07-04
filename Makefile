game:
	g++ src/main.cpp src/screen.cpp src/gameover.cpp src/gameplay.cpp src/texture.cpp src/gameMap.cpp src/tetromino.cpp src/score.cpp -o main -I include -L lib -l SDL2-2.0.0 -l SDL2_image-2.0.0