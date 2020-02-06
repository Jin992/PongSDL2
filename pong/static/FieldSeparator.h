//
// Created by jin on 04.02.20.
//

#ifndef PONGSDL2_FIELDSEPARATOR_H
#define PONGSDL2_FIELDSEPARATOR_H
#include <ui/Rectangle.h>
#include <memory>
#include <vector>

namespace PongGame {
class FieldSeparator: public Engine::entity::Entity {
    public:
        void setColor(int32_t color);
        void init(int32_t x, int32_t y, int32_t w, int32_t h,  int32_t padding);
        void render(Engine::Renderer::engine_renderer &renderer) override;
        void update() override {}

    private:
        std::vector<std::shared_ptr<Engine::ui::Rectangle>> _separator;
        int32_t _color;

    };
}


#endif //PONGSDL2_FIELDSEPARATOR_H
