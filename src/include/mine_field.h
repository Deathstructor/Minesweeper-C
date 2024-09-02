#ifndef __MINE_FIELD_H__
#define __MINE_FIELD_H__

#include "common.h"

void mine_field_update(f32 delta_time);
void mine_field_render();

typedef enum mine_spawn_chance
{
    msc_easy = 50,
    msc_medium = 25,
    msc_hard = 10,
    msc_impossible = 5
} mine_spawn_chance;

#endif