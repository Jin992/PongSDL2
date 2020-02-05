//
// Created by jin on 04.02.20.
//

#ifndef PONGSDL2_FIELDSEPARATOR_H
#define PONGSDL2_FIELDSEPARATOR_H
#include <iface/IEngineObject.h>
#include <ui/Rectangle.h>
#include <memory>
#include <vector>

namespace PongGame {
class FieldSeparator: public Engine::entity::Entity {
    public:

        void setColor(int32_t color){
            _color = color;
        }

        void init(int32_t x, int32_t y, int32_t w, int32_t h,  int32_t padding) {
            uint64_t rect_qnt = 800 / (h + padding);
            for (uint64_t i = 0; i < rect_qnt; i++) {
                auto rect = std::make_shared<Engine::ui::Rectangle>(Engine::ui::Rectangle());
                rect->type(Engine::IEngineObject::Static);
                rect->init(x, y, w, h, _color);
                _separator.push_back(rect);
                y += h + padding;
            }
        }

    void render(Engine::Renderer::engine_renderer &renderer) override {
            for(auto it : _separator)
                it->render(renderer);
        }

    void update() override {}

    private:
        std::vector<std::shared_ptr<Engine::ui::Rectangle>> _separator;
        int32_t _color;

    };
}


#endif //PONGSDL2_FIELDSEPARATOR_H
