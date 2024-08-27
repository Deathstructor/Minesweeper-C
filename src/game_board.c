#include "include/game_board.h"

void game_board_update(f32 delta_time)
{
}

void game_board_render()
{
    for (u16 pos_x = 0; pos_x < BOARD_SIZE; pos_x += TILE_SIZE)
    {
        for (u16 pos_y = 0; pos_y < BOARD_SIZE; pos_y += TILE_SIZE)
        {
            Rectangle game_tile = {pos_x, pos_y + TILE_OFFSET, pos_x + TILE_SIZE, pos_y + TILE_OFFSET + TILE_SIZE};
            DrawRectangleLinesEx(game_tile, 1.5, BLACK);
        }
    }
}