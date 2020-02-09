//
// Created by jin on 04.02.20.
//

#ifndef PONGSDL2_RECTANGLE_H
#define PONGSDL2_RECTANGLE_H

#include <entity/Entity.h>
#include <iface/IPressObject.h>
#include "UIEntity.h"
#include <SDL2/SDL_rect.h>

namespace Engine {
    namespace ui {
    class Rectangle: public entity::Entity, public IPressObject {
        public:
            Rectangle() = default;
            Rectangle(int32_t x, int32_t y, int32_t w, int32_t h, int32_t color);
            void render(Renderer::engine_renderer &renderer) override;
            void init(int32_t x, int32_t y, int32_t w, int32_t h, int32_t color);
            void update(double) override;
            int32_t color() const;
            void color(int32_t color);

        private:
            int32_t _color;
        };
    }
}



#endif //PONGSDL2_RECTANGLE_H
