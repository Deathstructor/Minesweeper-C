#include "include/info_bar.h"

void info_bar_update(f32 delta_time)
{
    if (timer < 999 && !timer_stop)
    {
        timer += delta_time;
    }
}

void info_bar_render()
{
    DrawTexture(info_box_texture, 10, 10, WHITE);
    DrawTexture(info_box_texture, 853, 10, WHITE);

    Vector2 number_placeholder = MeasureTextEx(digital_font, "888", 60, 0);
    Vector2 time_text = MeasureTextEx(digital_font, TextFormat("%d", (int)timer), 60, 0);
    Vector2 mine_text = MeasureTextEx(digital_font, TextFormat("%d", mine_count - flag_count), 60, 0);

    // Draws the mine count
    DrawTextEx(digital_font, "888", (Vector2){20, 20}, 60, 0, (Color){80, 0, 0, 255});
    DrawTextEx(
        digital_font,
        TextFormat("%d", mine_count - flag_count), (Vector2){20 + (number_placeholder.x - mine_text.x), 20},
        60,
        0,
        (Color){255, 0, 0, 255});

    // Draws the timer
    DrawTextEx(digital_font, "888", (Vector2){863, 20}, 60, 0, (Color){80, 0, 0, 255});
    DrawTextEx(
        digital_font,
        TextFormat("%d", (int)timer), (Vector2){863 + (number_placeholder.x - time_text.x), 20},
        60,
        0,
        (Color){255, 0, 0, 255});
}