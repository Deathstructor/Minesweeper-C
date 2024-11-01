#ifndef __INFO_BAR_H__
#define __INFO_BAR_H__

#include "common.h"

void info_bar_update(f32 delta_time);
void info_bar_render();

f32 timer = 0;
bool timer_stop = false;

#endif