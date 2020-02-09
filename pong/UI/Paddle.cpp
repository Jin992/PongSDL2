//
// Created by jin on 2/4/20.
//

#include "Paddle.h"
#include <config/config.h>

namespace PongGame {
    Paddle::Paddle()
    : _scene_height(Engine::EngineData::EngineData::instance().window().height()), _cur_pos(0.0f){
        type(Engine::entity::Collidable);
        init(0, 0,0,0, c_paddle_color);
    }

    Paddle::Paddle(int32_t x, int32_t y, uint32_t w, int32_t h, uint32_t color)
    : Engine::ui::Rectangle(x, y, w, h, color),
    _scene_height(Engine::EngineData::EngineData::instance().window().height()), _cur_pos(y - h /2) {
        type(Engine::entity::Collidable);
    }

    void Paddle::moveUp(double elapsed){
        if (y() > c_paddle_padding) {
            _cur_pos -= c_paddle_y_speed * elapsed;
            set_y(_cur_pos);
        }
    }

    void Paddle::moveDown(double elapsed) {
        if (y() < _scene_height - c_paddle_padding - c_paddle_h) {
            _cur_pos += c_paddle_y_speed * elapsed;
            set_y(_cur_pos);
        }
    }

    void Paddle::moveUp() {
        if (y() > c_paddle_padding) set_y(y() - c_paddle_y_speed / 100);
    }

    void Paddle::moveDown() {
        if (y() < _scene_height - c_paddle_padding - c_paddle_h) set_y(y() + c_paddle_y_speed / 100);
    }
}