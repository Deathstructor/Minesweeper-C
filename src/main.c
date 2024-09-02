// Libraries
#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <stdlib.h>

// Header Files
#include "include/common.h"
#include "include/game_board.h"
#include "include/mine_field.h"

// Source Files
#include "game_board.c"
#include "mine_field.c"

// Updates logic
void update(f32 delta_time) {
    game_board_update(delta_time);
}

// Updates graphics
void render() {
    BeginDrawing();
    ClearBackground(GRAY);

    game_board_render();
    mine_field_render();

    EndDrawing();
}

// Main function
int main() {
    SetTargetFPS(60);
    InitWindow(1000, 1100, "Minesweeper");

    while (!WindowShouldClose())
    {
        update(GetFrameTime());
        render();
    }
    
}