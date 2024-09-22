#include "include/game_board.h"

void game_board_update(f32 delta_time)
{
    game_board_generate();
}

void game_board_generate()
{
    if (!game_board_generated)
    {
        for (u16 i = 0; i < TILE_MULTIPLIER; i++)
        {
            for (u16 j = 0; j < TILE_MULTIPLIER; j++)
            {
                grid[i][j] = (tile_s){
                    .ROWS = i,
                    .COLS = j,
                    .CONTAINS_MINE = false,
                    .REVEALED = false,
                    .SURROUNDING_MINES = 0,
                    .FLAGGED = false};
            }
        }
        game_board_generated = true;
    }
}

Color tile_get_color(tile_s tile)
{
    if (tile.FLAGGED)
    {
        return GREEN;
    }
    else
    {
        return tile.REVEALED ? DARKGRAY : GRAY;
    }
}

void tile_draw(tile_s tile)
{
    Color tile_color = tile_get_color(tile);

    Rectangle tile_rect = {tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, TILE_SIZE, TILE_SIZE};
    DrawRectangleRec(tile_rect, tile_color);
    DrawRectangleLinesEx(tile_rect, 1.5, BLACK);
}

void game_board_render()
{
    for (i16 i = 0; i < TILE_MULTIPLIER; i++)
    {
        for (u16 j = 0; j < TILE_MULTIPLIER; j++)
        {
            tile_draw(grid[i][j]);
        }
    }
}