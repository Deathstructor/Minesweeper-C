#ifndef __GAME_BOARD_H__
#define __GAME_BOARD_H__

#include "common.h"

void game_board_update(f32 delta_time);
void game_board_generate();
void tile_draw(tile_s tile);
void game_board_render();

bool game_board_generated = false;

#endif