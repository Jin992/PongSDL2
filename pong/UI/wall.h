//
// Created by jin on 2/4/20.
//

#ifndef PONGSDL2_WALL_H
#define PONGSDL2_WALL_H

#include <ui/Rectangle.h>

namespace PongGame {
class Wall: public Engine::ui::Rectangle {
    public:
        Wall() {
            type(Engine::IEngineObject::Collidable);
            init(0, 0,0,0, 0x00);
        }

        Wall(int32_t x, int32_t y, uint32_t w, int32_t h, uint32_t color) {
            init(x, y, w, h, color);
        }

    };
}



#endif //PONGSDL2_WALL_H
