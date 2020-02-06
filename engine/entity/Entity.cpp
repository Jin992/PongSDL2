//
// Created by jin on 2/1/20.
//

#include "Entity.h"

namespace Engine {
    namespace entity {
        Entity::Entity(): _rect{0,0,0,0}
        {}

        int32_t Entity::x() const {
            return _rect.x;
        }

        int32_t Entity::y() const {
            return _rect.y;
        }

        int32_t Entity::w() const {
            return _rect.w;
        }

        int32_t Entity::h() const {
            return _rect.h;
        }

        void Entity::set_x(int32_t val) {
            _rect.x = val;
        }

        void Entity::set_y(int32_t val) {
            _rect.y = val;
        }

        void Entity::set_h(int32_t val) {
            _rect.h = val;
        }

        void Entity::set_w(int32_t val) {
            _rect.w = val;
        }

        int32_t	Entity::type() const {
            return _type;
        }

        void	Entity::type(int32_t v) {
            _type = v;
        }

        SDL_Rect &Entity::rect() {
            return _rect;
        }

    }
}