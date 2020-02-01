//
// Created by root on 1/30/20.
//

#ifndef PONGSDL2_POINT_H
#define PONGSDL2_POINT_H


#include <cstdint>

namespace Engine {
    class Point {
    public:
        Point();
        Point(uint32_t x, uint32_t y);
        uint32_t x() const;
        uint32_t y() const;
        void x(uint32_t);
        void y(uint32_t);

        Point operator+(Point const &);
        Point operator-(Point const &);

    private:
        uint32_t _x;
        uint32_t _y;
};
}



#endif //PONGSDL2_POINT_H
