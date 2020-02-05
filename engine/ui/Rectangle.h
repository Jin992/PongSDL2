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
            Rectangle(): Entity(0, 0, 0, 0) {}
            Rectangle(int32_t x_, int32_t y_, int32_t w_, int32_t h_, int32_t color)
            : Entity(x_, y_, w_, h_) {
                entity_color(color);
                _rect = SDL_Rect{x(), y(), w(), h()};
            }
            void init(int32_t x_, int32_t y_, int32_t w_, int32_t h_, int32_t color) {
                init_entity(x_, y_, w_, h_);
                entity_color(color);
                _rect = SDL_Rect{x(), y(), w(), h()};
                //texture(SDL_CreateTextureFromSurface(data.renderer().get().get(), sufrace.get()));)
            }
            void render(Renderer::engine_renderer &renderer) override {
                SDL_SetRenderDrawColor(renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderFillRect(renderer.get(), &_rect);
            }

            void update() override{}
            int32_t color() const {
               return entity_color();
            }

            void color(int32_t color) {
                entity_color(color);
            }

    private:
        SDL_Rect _rect;
        };
    }
}



#endif //PONGSDL2_RECTANGLE_H
