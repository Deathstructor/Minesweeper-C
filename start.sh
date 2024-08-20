clear
rm Build/Minesweeper
cc main.c `pkg-config --libs --cflags raylib` -o Build/Minesweeper
./Build/Minesweeper