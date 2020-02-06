//
// Created by jin on 2/4/20.
//

#include "Paddle.h"

namespace PongGame {
    Paddle::Paddle(): _scene_height(Engine::EngineData::EngineData::instance().window().height()){
        type(Engine::entity::Collidable);
        init(0, 0,0,0, 0xffffff);
    }

    Paddle::Paddle(int32_t x, int32_t y, uint32_t w, int32_t h, uint32_t color)
    : Engine::ui::Rectangle(x, y, w, h, color),
    _scene_height(Engine::EngineData::EngineData::instance().window().height()){
    type(Engine::entity::Collidable);
}

void Paddle::moveUp(){
    if (y() > 15) set_y(y() - 5);
}
void Paddle::moveDown() {
    if (y() < _scene_height - 15 - 120) set_y(y() + 5);
}
}