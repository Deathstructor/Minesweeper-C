#include "include/mine_field.h"

void mine_field_generate()
{
    if (!mine_field_generated)
    {
        for (u16 i = 0; i < TILE_MULTIPLIER; i++)
        {
            for (u16 j = 0; j < TILE_MULTIPLIER; j++)
            {
                u16 mine_spawn_chance = GetRandomValue(0, msc_hard);

                if (mine_spawn_chance == 0)
                {
                    grid[i][j] = (tile_s){.ROWS = i, .COLS = j, .CONTAINS_MINE = true, .REVEALED = false};
                    mine_count++;
                }
            }
        }
        mine_field_generated = true;
    }
}

void mine_field_update(f32 delta_time)
{
    mine_field_generate();
}