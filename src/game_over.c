#include "include/game_over.h"
#include "include/game_board.h"
#include "include/mine_field.h"

void game_over_render()
{
    Vector2 mouse_pos = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        u16 mouse_x = mouse_pos.x / TILE_SIZE;
        u16 mouse_y = (mouse_pos.y - TILE_OFFSET) / TILE_SIZE;

        if (!isIndexValid(mouse_x, mouse_y))
        {
            return;
        }

        if (grid[mouse_x][mouse_y].CONTAINS_MINE)
        {
            for (u16 i = 0; i < TILE_MULTIPLIER; i++)
            {
                for (u16 j = 0; j < TILE_MULTIPLIER; j++)
                {
                    grid[i][j].REVEALED = true;
                }
            }

            game_over = true;
        }
    }

    if (game_over)
    {
        Rectangle restart = {400, 525, 200, 50};
        Rectangle view_board = {400, 600, 200, 50};

        DrawRectangle(250, 400, 500, 300, ColorAlpha(BLACK, 0.75f));
        DrawText("GAME OVER", 350, 450, 50, RED);

        bool hover_restart = false;
        if (CheckCollisionPointRec(mouse_pos, restart))
        {
            hover_restart = true;

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                game_board_generated = false;
                mine_field_generated = false;
                game_over = false;
            }
        }
        DrawRectangleRec(restart, hover_restart ? (Color){150, 0, 0, 255} : RED);
        DrawText("Restart", 440, 535, 30, WHITE);

        bool hover_view_board = false;
        if (CheckCollisionPointRec(mouse_pos, view_board))
        {
            hover_view_board = true;

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                /* code */
            }
        }
        DrawRectangleRec(view_board, hover_view_board ? (Color){150, 0, 0, 255} : RED);
        DrawText("View Board", 415, 610, 30, WHITE);
    }
}