//
// Created by jin on 2/4/20.
//

#ifndef PONGSDL2_PADDLE_H
#define PONGSDL2_PADDLE_H

#include <ui/Rectangle.h>
#include <iostream>

namespace PongGame {
    class Paddle: public Engine::ui::Rectangle {
    public:
        Paddle();
        Paddle(int32_t x, int32_t y, uint32_t w, int32_t h, uint32_t color);
        void moveUp();
        void moveDown();

        private:
        int32_t _scene_height;
    };
}


#endif //PONGSDL2_PADDLE_H
