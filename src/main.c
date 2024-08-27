// Libraries
#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <stdlib.h>

// Header Files
#include "include/common.h"
#include "include/game_board.h"

// Source Files
#include "game_board.c"

// Updates logic
void update(f32 delta_time) {

}

// Updates graphics
void render() {
    BeginDrawing();
    ClearBackground(GRAY);

    game_board_render();

    EndDrawing();
}

// Main function
int main() {
    SetTargetFPS(60);
    InitWindow(1000, 1100, "Minesweeper");

    while (!WindowShouldClose())
    {
        render();
    }
    
}