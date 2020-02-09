//
// Created by jin on 2/4/20.
//

#ifndef PONGSDL2_BALL_H
#define PONGSDL2_BALL_H

#include <ui/Rectangle.h>

namespace PongGame {
class Ball: public Engine::ui::Rectangle{
    public:
        Ball();
        Ball(int32_t x, int32_t y, uint32_t w, int32_t h, uint32_t color);
        void spawn_point(int32_t x, int32_t y);
        void respawn();
        void set_xspeed(double speed);
        void accelerate(double);
        void changeXdirection();
        void changeYdirection();
        void setXspeed(double val);
        void setYspeed(double val);
        double xSpeed() const;
        double ySpeed() const;



    private:
        double  _xspeed;
        double  _yspeed;
        int32_t _spawn_x;
        int32_t _spawn_y;
        double  _ball_x;
        double  _ball_y;
};
}


#endif //PONGSDL2_BALL_H
