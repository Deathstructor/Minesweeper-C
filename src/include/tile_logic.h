#ifndef __TILE_LOGIC_H__
#define __TILE_LOGIC_H__

#include "common.h"

bool isIndexValid(i16 i, i16 j);
u16 check_surrounding_mines(u16 x, u16 y);
void tile_reveal(u16 x, u16 y);
void tile_logic_update(f32 delta_time);
void tile_logic_render();

#endif