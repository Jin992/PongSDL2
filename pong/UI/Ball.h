//
// Created by jin on 2/4/20.
//

#ifndef PONGSDL2_BALL_H
#define PONGSDL2_BALL_H

#include <ui/Rectangle.h>

namespace PongGame {
class Ball: public Engine::ui::Rectangle {
    public:
        Ball();

    private:
    std::shared_ptr<Engine::ui::Rectangle> _bal;
    };
}


#endif //PONGSDL2_BALL_H
