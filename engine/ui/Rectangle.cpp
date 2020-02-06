//
// Created by jin on 04.02.20.
//

#include "Rectangle.h"
namespace Engine {
    namespace ui {
            Rectangle::Rectangle(int32_t x, int32_t y, int32_t w, int32_t h, int32_t color)
            : _color(color)
            {
                set_x(x);
                set_y(y);
                set_w(w);
                set_h(h);
            }

            void Rectangle::render(Renderer::engine_renderer &renderer) {
                auto rbga = reinterpret_cast<int8_t*>(&_color);
                SDL_SetRenderDrawColor(renderer.get(), rbga[0], rbga[1], rbga[2], rbga[3]);
                SDL_RenderFillRect(renderer.get(), &rect());
            }

        void Rectangle::init(int32_t x, int32_t y, int32_t w, int32_t h, int32_t color) {
            set_x(x);
            set_y(y);
            set_w(w);
            set_h(h);
            _color = color;
        }

        void Rectangle::update() {}

        int32_t Rectangle::color() const {
            return _color;
        }

        void Rectangle::color(int32_t color) {
            _color = color;
        }
    }
}