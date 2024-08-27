#ifndef __GAME_BOARD_H__
#define __GAME_BOARD_H__

#include "common.h"

#define TILE_SIZE 50
#define TILE_MULTIPLIER 20
#define BOARD_SIZE TILE_SIZE * TILE_MULTIPLIER
#define TILE_OFFSET 100

void game_board_update(f32 delta_time);
void game_board_render();

#endif