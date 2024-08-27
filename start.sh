clear
rm Build/Minesweeper
cc src/main.c `pkg-config --libs --cflags raylib` -o Build/Minesweeper
./Build/Minesweeper