#ifndef __GAME_BOARD_H__
#define __GAME_BOARD_H__

#include "common.h"

void game_board_update(f32 delta_time);
void game_board_render();
void game_board_generate();

bool game_board_generated = false;

tile_s grid[TILE_MULTIPLIER][TILE_MULTIPLIER];

#endif