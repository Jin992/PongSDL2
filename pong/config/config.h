//
// Created by jin on 2/8/20.
//

#ifndef PONGSDL2_CONFIG_H
#define PONGSDL2_CONFIG_H

#include <cstdint>
#define COLOR_WHITE 0xffffff
#define COLOR_BLACK 0x000000
#define COLOR_BLUE 0xff4c4c
#define COLOR_RED   0x4c4cff

// Game field scene
constexpr int32_t c_paddle_h = 120;
constexpr int32_t c_paddle_w = 20;
constexpr int32_t c_paddle_color = COLOR_WHITE;
constexpr int32_t c_paddle_y_speed = 200;
constexpr int32_t c_paddle_padding = 15;

constexpr int32_t c_ball_h = 25;
constexpr int32_t c_ball_w = 25;
constexpr int32_t c_ball_color = COLOR_WHITE;
constexpr int32_t c_ball_x_speed = 180;
constexpr int32_t c_ball_y_speed = 180;

constexpr int32_t c_wall_h = 10;
constexpr int32_t c_wall_color = COLOR_WHITE;

constexpr int32_t c_field_sep_w = 6;
constexpr int32_t c_field_sep_h = 24;
constexpr int32_t c_field_sep_padding = 20;
constexpr int32_t c_field_sep_color = COLOR_WHITE;


// Main Menu scene
constexpr int32_t c_menu_x = 400;
constexpr int32_t c_menu_y = 350;
// title
constexpr int32_t c_menu_title_font_size = 165;
constexpr int32_t c_menu_title_color = COLOR_BLUE;
constexpr int32_t c_menu_title_x = 400;
constexpr int32_t c_menu_title_y = 60;
// items
constexpr int32_t c_menu_item_font_size = 48;
constexpr int32_t c_menu_item_padding = 40;
constexpr int32_t c_menu_item_active_color = COLOR_RED;
constexpr int32_t c_menu_item_color = COLOR_WHITE;


// Credits scene
constexpr int32_t c_credits_title_font_size = 45;
constexpr int32_t c_credits_title_x = 400;
constexpr int32_t c_credits_title_y = 100;
constexpr int32_t c_credits_title_color = COLOR_BLUE;
constexpr int32_t c_credits_exit_label_font_size = 25;
constexpr int32_t c_credits_exit_label_x = 400;
constexpr int32_t c_credits_exit_label_y = 390;
constexpr int32_t c_credits_exit_label_color = COLOR_WHITE;


#endif //PONGSDL2_CONFIG_H
