// Libraries
#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <stdlib.h>

// Header Files
#include "include/common.h"
#include "include/game_board.h"
#include "include/mine_field.h"
#include "include/tile_logic.h"
#include "include/game_over.h"

// Source Files
#include "game_board.c"
#include "mine_field.c"
#include "tile_logic.c"
#include "game_over.c"

// Updates logic
void update(f32 delta_time) {
    game_board_update(delta_time);
    mine_field_update(delta_time);
    tile_logic_update(delta_time);
}

// Updates graphics
void render() {
    BeginDrawing();
    ClearBackground(GRAY);

    game_board_render();
    game_over_render();

    EndDrawing();
}

void init_images()
{
    Image img_one = LoadImage("src/assets/one.png");
    Image img_two = LoadImage("src/assets/two.png");
    Image img_three = LoadImage("src/assets/three.png");
    Image img_four = LoadImage("src/assets/four.png");
    Image img_five = LoadImage("src/assets/five.png");
    Image img_six = LoadImage("src/assets/six.png");
    Image img_seven = LoadImage("src/assets/seven.png");
    Image img_eight = LoadImage("src/assets/eight.png");
    Image img_blank = LoadImage("src/assets/blank.png");
    Image img_flag = LoadImage("src/assets/flag.png");
    Image img_mine = LoadImage("src/assets/mine.png");
    Image img_tile = LoadImage("src/assets/tile.png");

    tile_one = LoadTextureFromImage(img_one);
    tile_two = LoadTextureFromImage(img_two);
    tile_three = LoadTextureFromImage(img_three);
    tile_four = LoadTextureFromImage(img_four);
    tile_five = LoadTextureFromImage(img_five);
    tile_six = LoadTextureFromImage(img_six);
    tile_seven = LoadTextureFromImage(img_seven);
    tile_eight = LoadTextureFromImage(img_eight);
    tile_blank = LoadTextureFromImage(img_blank);
    tile_flag = LoadTextureFromImage(img_flag);
    tile_mine = LoadTextureFromImage(img_mine);
    tile_tile = LoadTextureFromImage(img_tile);

    UnloadImage(img_one);
    UnloadImage(img_two);
    UnloadImage(img_three);
    UnloadImage(img_four);
    UnloadImage(img_five);
    UnloadImage(img_six);
    UnloadImage(img_seven);
    UnloadImage(img_eight);
    UnloadImage(img_blank);
    UnloadImage(img_flag);
    UnloadImage(img_mine);
    UnloadImage(img_tile);
}

// Main function
int main() {
    SetTargetFPS(60);
    InitWindow(1000, 1100, "Minesweeper");

    init_images();

    while (!WindowShouldClose())
    {
        update(GetFrameTime());
        render();
    }
    
}