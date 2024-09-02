#include "include/mine_field.h"

void mine_field_update(f32 delta_time)
{
}

void mine_field_render()
{
    for (u16 pos_x = 0; pos_x < BOARD_SIZE; pos_x += TILE_SIZE)
    {
        for (u16 pos_y = 0; pos_y < BOARD_SIZE; pos_y += TILE_SIZE)
        {
            u16 mine_spawn_chance = GetRandomValue(0, msc_medium);

            if (mine_spawn_chance == 0)
            {
                // DrawCircle(pos_x + 5, pos_y + TILE_OFFSET + 5, 5, RED);
            }
            

            // Rectangle game_tile = {pos_x, pos_y + TILE_OFFSET, pos_x + TILE_SIZE, pos_y + TILE_OFFSET + TILE_SIZE};
            // DrawRectangleRec(game_tile, BLANK);
        }
    }
}