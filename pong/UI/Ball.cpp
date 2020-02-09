//
// Created by jin on 2/4/20.
//

#include <iostream>
#include "Ball.h"
#include <config/config.h>

namespace PongGame {
    Ball::Ball():_xspeed(c_ball_x_speed), _yspeed(c_ball_y_speed) {
        type(Engine::entity::Collidable);
        init(0, 0,0,0, c_ball_color);
    }

    Ball::Ball(int32_t x, int32_t y, uint32_t w, int32_t h, uint32_t color)
    : _xspeed(c_ball_x_speed), _yspeed(c_ball_y_speed), _spawn_x(x), _spawn_y(y) {
        type(Engine::entity::Collidable);
        init(x, y, w, h, color);
        _ball_x = x;
        _ball_y = y;
    }

    void Ball::spawn_point(int32_t x, int32_t y) {
    _spawn_x = x;
    _spawn_y = y;
}

void Ball::respawn() {
    _ball_x = _spawn_x;
    _ball_y = _spawn_y;
    changeXdirection();
}
void Ball::set_xspeed(double speed) {
    _xspeed = speed;
}

void Ball::accelerate(double elapsed) {
    _ball_x += _xspeed * elapsed;
    _ball_y += _yspeed * elapsed;
    set_x(_ball_x);
    set_y(_ball_y);
}

void Ball::changeXdirection() {
    _xspeed *= -1;
}

void Ball::changeYdirection() {
    _yspeed *= -1;
}


void Ball::setXspeed(double val){
        _xspeed = val;
    }

void Ball::setYspeed(double val){ _yspeed = val;}

double Ball::xSpeed() const {
    return _xspeed;
}

double Ball::ySpeed() const {
    return _yspeed;
}

}