#include "include/game_over.h"

void game_over_update(f32 delta_time)
{
}

void game_over_render()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mouse_pos = GetMousePosition();
        u16 mouse_x = mouse_pos.x / TILE_SIZE;
        u16 mouse_y = (mouse_pos.y - TILE_OFFSET) / TILE_SIZE;

        if (!isIndexValid(mouse_x, mouse_y))
        {
            return;
        }

        if (grid[mouse_x][mouse_y].CONTAINS_MINE)
        {
            for (u16 i = 0; i < TILE_MULTIPLIER; i++)
            {
                for (u16 j = 0; j < TILE_MULTIPLIER; j++)
                {
                    grid[i][j].REVEALED = true;
                }
            }
        }
    }
}