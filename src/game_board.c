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

void tile_draw(tile_s tile)
{
    if (!tile.REVEALED)
    {
        if (tile.FLAGGED)
        {
            DrawTexture(tile_flag, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
        }
        else
        {
            DrawTexture(tile_tile, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
        }
    }
    else
    {
        if (tile.CONTAINS_MINE)
        {
            DrawTexture(tile_mine, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
        }
        else
        {
            switch (tile.SURROUNDING_MINES)
            {
            case 0:
                DrawTexture(tile_blank, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
                break;
            case 1:
                DrawTexture(tile_one, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
                break;
            case 2:
                DrawTexture(tile_two, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
                break;
            case 3:
                DrawTexture(tile_three, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
                break;
            case 4:
                DrawTexture(tile_four, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
                break;
            case 5:
                DrawTexture(tile_five, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
                break;
            case 6:
                DrawTexture(tile_six, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
                break;
            case 7:
                DrawTexture(tile_seven, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
                break;
            case 8:
                DrawTexture(tile_eight, tile.ROWS * TILE_SIZE, tile.COLS * TILE_SIZE + TILE_OFFSET, WHITE);
                break;
            }
        }
    }
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