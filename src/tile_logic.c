#include "include/tile_logic.h"

void tile_place_flag(u16 x, u16 y)
{
    if (!grid[x][y].REVEALED)
    {
        grid[x][y].FLAGGED = !grid[x][y].FLAGGED;
    }
}

bool isIndexValid(i16 i, i16 j)
{
    return i >= 0 && i < TILE_MULTIPLIER && j >= 0 && j < TILE_MULTIPLIER;
}

u16 check_surrounding_mines(u16 x, u16 y)
{
    u16 surrounding_mines = 0;

    for (i16 i = -1; i <= 1; i++)
    {
        for (i16 j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            u16 neighbor_x = x + i;
            u16 neighbor_y = y + j;

            if (grid[neighbor_x][neighbor_y].CONTAINS_MINE &&
                neighbor_x >= 0 && neighbor_x < TILE_MULTIPLIER &&
                neighbor_y >= 0 && neighbor_y < TILE_MULTIPLIER)
            {
                surrounding_mines++;
            }
        }
    }

    return surrounding_mines;
}

void tile_reveal(u16 x, u16 y)
{
    if (grid[x][y].REVEALED || grid[x][y].FLAGGED)
    {
        return;
    }

    grid[x][y].REVEALED = true;

    if (!grid[x][y].CONTAINS_MINE && grid[x][y].SURROUNDING_MINES == 0)
    {
        for (i16 i = -1; i <= 1; i++)
        {
            for (i16 j = -1; j <= 1; j++)
            {
                if ((i == 0 && j == 0) || !isIndexValid(x + i, y + j))
                {
                    continue;
                }

                if (!grid[x + i][y + j].REVEALED)
                {
                    tile_reveal(x + i, y + j);
                }
            }
        }
    }
}

void tile_logic_update(f32 delta_time)
{
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        Vector2 mouse_pos = GetMousePosition();
        u16 mouse_x = mouse_pos.x / TILE_SIZE;
        u16 mouse_y = (mouse_pos.y - TILE_OFFSET) / TILE_SIZE;

        tile_place_flag(mouse_x, mouse_y);
    }

    for (u16 i = 0; i < TILE_MULTIPLIER; i++)
    {
        for (u16 j = 0; j < TILE_MULTIPLIER; j++)
        {
            grid[i][j].SURROUNDING_MINES = check_surrounding_mines(i, j);
        }
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mouse_pos = GetMousePosition();

        u16 mouse_x = mouse_pos.x / TILE_SIZE;
        u16 mouse_y = (mouse_pos.y - TILE_OFFSET) / TILE_SIZE;

        tile_reveal(mouse_x, mouse_y);
    }
}
