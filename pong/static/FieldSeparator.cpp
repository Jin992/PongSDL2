//
// Created by jin on 04.02.20.
//

#include "FieldSeparator.h"

namespace PongGame {
    void FieldSeparator::setColor(int32_t color){
        _color = color;
    }

    void FieldSeparator::init(int32_t x, int32_t y, int32_t w, int32_t h,  int32_t padding) {
        uint64_t rect_qnt = 800 / (h + padding);
        for (uint64_t i = 0; i < rect_qnt; i++) {
            auto rect = std::make_shared<Engine::ui::Rectangle>(Engine::ui::Rectangle());
            rect->type(Engine::entity::Static);
            rect->init(x, y, w, h, _color);
            _separator.push_back(rect);
            y += h + padding;
        }
    }

    void FieldSeparator::render(Engine::Renderer::engine_renderer &renderer) {
    for(auto it : _separator)
    it->render(renderer);
}
}