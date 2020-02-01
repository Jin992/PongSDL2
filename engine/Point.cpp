//
// Created by root on 1/30/20.
//

#include "Point.h"

namespace Engine {

    Point::Point()
    : _x(0), _y(0)
    {}

    Point::Point(uint32_t x, uint32_t y)
    : _x(x), _y(y)
    {}

    uint32_t Point::x() const {
        return _x;
    }

    uint32_t Point::y() const {
        return _y;
    }

    void Point::x(uint32_t v) {
        _x = v;
    }

    void Point::y(uint32_t v) {
        _y = v;
    }

    Point Point::operator+(Point const &rhs) {
        return Point(_x + rhs._x, _y + rhs._y);
    }

    Point Point::operator-(Point const &rhs) {
        return Point(_x - rhs._x, _y - rhs._y);
    }

}