#ifndef CNAKE_TITLE_SCREEN_H
#define CNAKE_TITLE_SCREEN_H

#include "raylib.h"
#include "snake.h"
#include "types.h"
#include "game.h"

/*
typedef enum {
        IDLE = 0,
        HOVERED,
        PRESSED
} ButtonState;
*/

static bool ui_label_button(Rectangle box, const char* text);
static void handle_title_screen(const u32 screen_width, const u32 screen_height, Game* game);
static void draw_title_screen(const u32 screen_width, const u32 screen_height, Game* game);

static void handle_title_screen(const u32 screen_width, const u32 screen_height, Game* game) {
        BeginDrawing();
                if (IsKeyPressed(KEY_ENTER)) {
                        game->state = PLAYING;
                }

                draw_title_screen(screen_width, screen_height, game);
        EndDrawing();
}

static void draw_title_screen(const u32 screen_width, const u32 screen_height, Game* game) {
        const u8 font_size = 40;
        const Color color = BLACK;

        const u32 center_x = screen_width / 2;
        const u32 center_y = screen_height / 2;


        ClearBackground(RAYWHITE);
        const char* title_str = "Chose A Mode Or Press [Enter] To Start The Game!";
        DrawText(title_str,
                center_x - MeasureText(title_str, font_size) / 2,
                center_y - font_size,
                font_size,
                color
        );

        const u16 btn_width = 200;
        const u8 total_buttons = 4;
        const float btn_x = (float)(center_x - ((btn_width + 10) * ((float)total_buttons / 2)));
        const float btn_y = (float)(center_y + font_size + 40);

        if (ui_label_button((Rectangle){ btn_x , btn_y, btn_width, 50}, "Slow")) {
                game->snake.speed_mode = SLOW;
                game->state = PLAYING;
        } else if (ui_label_button((Rectangle){btn_x + btn_width + 10, btn_y, btn_width, 50}, "Normal")) {
                game->snake.speed_mode = NORMAL;
                game->state = PLAYING;
        } else if (ui_label_button((Rectangle){btn_x + (btn_width * 2) + 20, btn_y, btn_width, 50}, "Fast")) {
                game->snake.speed_mode = FAST;
                game->state = PLAYING;
        } else if (ui_label_button((Rectangle){btn_x + (btn_width * 3) + 30, btn_y, btn_width, 50}, "Blazingly fast")) {
                game->snake.speed_mode = BLAZINGLY_FAST;
                game->state = PLAYING;
        }
}

static bool ui_label_button(Rectangle bounds, const char* text) {
        const Vector2 mouse_pos = GetMousePosition();
        const bool mouse_over = CheckCollisionPointRec(mouse_pos, bounds);
        const u8 font_size = 20;

        u16 text_width = MeasureText(text, font_size);
        float text_x = bounds.x + (bounds.width - text_width) / 2;
        float text_y = bounds.y + (bounds.height - font_size) / 2;


        if (mouse_over) {
                DrawText(text, text_x, text_y, font_size, RED);
        } else {
                DrawText(text, text_x, text_y, font_size, BLACK);
        }

        return (mouse_over && IsMouseButtonDown(MOUSE_BUTTON_LEFT));
}

#endif
