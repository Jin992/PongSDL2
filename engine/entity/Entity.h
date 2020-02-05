//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_ENTITY_H
#define PONGSDL2_ENTITY_H

#include "../iface/IRendererObject.h"
#include <renderer/Renderer.h>
#include <memory>


namespace Engine {
    namespace entity {
        class Entity;

        typedef std::shared_ptr<Entity> engine_entity_ptr;
        typedef std::shared_ptr<SDL_Texture>  engine_texture;


        class Entity : public IRendererObject {
        public:
            Entity(): _x(0), _y(0), _w(0), _h(0), _visible(true)
            {}

            Entity(int32_t x, int32_t y, int32_t w=0, int32_t h=0)
            : _x(x), _y(y), _w(w), _h(h), _visible(true)
            {}

        protected:
            void init_entity(int32_t x, int32_t y, int32_t w=0, int32_t h=0) {
               _x = x;
               _y = y;
               _w = w;
               _h = h;
            }

            //void render(Renderer::engine_renderer &renderer) override {
            //}

            bool visible() const {
                return _visible;
            }

            void visible(bool status) {
                _visible = status;
            }

            int32_t x() const {
                return _x;
            }

            int32_t  y() const {
                return _y;
            }

            int32_t w() const {
                return _w;
            }

            int32_t h() const {
                return _h;
            }

            int32_t entity_color() const {
                return _color;
            }

            void entity_color(int32_t v) {
                _color = v;
            }


        private:

            int32_t                 _x;
            int32_t                 _y;
            int32_t                 _w;
            int32_t                 _h;
            bool                    _visible;
            int32_t                 _color;
        };
    }
}

#endif //PONGSDL2_ENTITY_H
