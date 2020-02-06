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

        enum {
            Static,
            Pressable,
            Collidable
        };

        class Entity : public IRendererObject {
        public:
            Entity();
            virtual ~Entity() = 0;
            int32_t x() const;
            int32_t y() const;
            int32_t w() const;
            int32_t h() const ;

            void set_x(int32_t);
            void set_y(int32_t);
            void set_h(int32_t);
            void set_w(int32_t);
            int32_t	type() const;
            void	type(int32_t v);

        protected:
            SDL_Rect &rect();

        private:
            SDL_Rect                _rect;
            int64_t                 _type;
        };

        inline  Entity::~Entity() {}
    }
}

#endif //PONGSDL2_ENTITY_H
