#include "include/tile_logic.h"

void tile_logic_update(f32 delta_time)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mouse_pos = GetMousePosition();

        i16 mouse_x = mouse_pos.x / TILE_SIZE;
        i16 mouse_y = (mouse_pos.y - TILE_OFFSET) / TILE_SIZE;

        grid[mouse_x][mouse_y].REVEALED = true;
    }
}

void tile_logic_render()
{
    // TODO: Add logic to render tile data
}