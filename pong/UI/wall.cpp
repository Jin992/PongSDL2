//
// Created by jin on 2/4/20.
//

#include "wall.h"

namespace PongGame {
    Wall::Wall() {
        type(Engine::entity::Static);
        init(0, 0,0,0, 0x00);
    }

    Wall::Wall(int32_t x, int32_t y, uint32_t w, int32_t h, uint32_t color) {
        type(Engine::entity::Static);
        init(x, y, w, h, color);
    }
}