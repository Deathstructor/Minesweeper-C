#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "raymath.h"

#define VERSION "0.0.0"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1100

#define TILE_SIZE 50
#define TILE_MULTIPLIER 20
#define BOARD_SIZE TILE_SIZE * TILE_MULTIPLIER
#define TILE_OFFSET 100

typedef uint8_t byte;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

typedef struct tile_s
{
    u16 ROWS;
    u16 COLS;
    bool CONTAINS_MINE;
    bool REVEALED;
} tile_s;

tile_s grid[TILE_MULTIPLIER][TILE_MULTIPLIER];

#endif