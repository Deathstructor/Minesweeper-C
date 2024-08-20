#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    SetTargetFPS(60);
    InitWindow(1000, 1100, "Minesweeper");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);
        EndDrawing();
    }
    
}