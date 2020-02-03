//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_ENTITY_H
#define PONGSDL2_ENTITY_H

#include "../iface/IRendererObject.h"
#include <renderer/Renderer.h>
#include <memory>
#include <iostream>

namespace Engine {
    namespace entity {
        class Entity;

        typedef std::shared_ptr<Entity> engine_entity_ptr;
        typedef std::shared_ptr<SDL_Texture>  engine_texture;


        class Entity : public IRendererObject {
        public:
            Entity(): _x(0), _y(0), _w(0), _h(0)
            {}

            Entity(int32_t x, int32_t y, int32_t w=0, int32_t h=0)
            : _x(x), _y(y), _w(w), _h(h)
            {}

            void init_entity(int32_t x, int32_t y, int32_t w=0, int32_t h=0) {
               _x = x;
               _y = y;
               _w = w;
               _h = h;
            }

            void render(Renderer::engine_renderer &renderer) final {
                SDL_Rect rect{_x, _y, _w, _h};
                SDL_QueryTexture(_texture.get(), nullptr, nullptr, &rect.w, &rect.h);
                rect.x -= rect.w / 2;
                SDL_RenderCopy(renderer.get(), _texture.get(), nullptr, &rect);
            }

            engine_texture texture() {
                return _texture;
            }

            void texture(engine_texture texture) {
                _texture = texture;
            }

        private:
            engine_texture          _texture;
            int32_t                 _x;
            int32_t                 _y;
            int32_t                 _w;
            int32_t                 _h;
        };
    }
}

#endif //PONGSDL2_ENTITY_H
