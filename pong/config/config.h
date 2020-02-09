//
// Created by jin on 2/8/20.
//

#ifndef PONGSDL2_CONFIG_H
#define PONGSDL2_CONFIG_H

#include <cstdint>
#define COLOR_WHITE 0xffffffff
#define COLOR_BLACK 0x00000000

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
//constexpr int32_t c_ball_speed = ;
//constexpr int32_t c_paddle_speed =


constexpr int32_t c_field_sep_w = 6;
constexpr int32_t c_field_sep_h = 24;
constexpr int32_t c_field_sep_padding = 20;
constexpr int32_t c_field_sep_color = COLOR_WHITE;


#endif //PONGSDL2_CONFIG_H
