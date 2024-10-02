#ifndef __MINE_FIELD_H__
#define __MINE_FIELD_H__

#define MINE_SIZE 15

#include "common.h"

void mine_field_generate();
void mine_field_update(f32 delta_time);

bool mine_field_generated = false;

typedef enum mine_spawn_chance
{
    msc_easy = 10,
    msc_medium = 5,
    msc_hard = 3,
    msc_impossible = 1
} mine_spawn_chance;

#endif