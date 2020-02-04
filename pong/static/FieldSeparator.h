//
// Created by jin on 04.02.20.
//

#ifndef PONGSDL2_FIELDSEPARATOR_H
#define PONGSDL2_FIELDSEPARATOR_H

#include <ui/Rectangle.h>

namespace PongGame {
    class FieldSeparator {
    public:
        void setWindow(int32_t win_h, int32_t win_w) {
             _win_h = win_h;
             _win_w = win_w;
        }

        void setColor(int32_t color){
            _color = color;
        }

        void init(int32_t x, int32_t y, int32_t w, int32_t h,  int32_t padding) {
            //int32_t _x = x;
            int32_t _y = y;

            uint64_t rect_qnt = _win_h / (h + padding);
            for (uint64_t i = 0; i < rect_qnt; i++) {
                auto rect = std::make_shared<Engine::ui::Rectangle>();
                rect->type(Engine::IEngineObject::Static);
                rect->init(x, y, w, h, _color);
                _separator.push_back(rect);
                _y += h + padding;
            }
        }

    private:
        std::vector<std::shared_ptr<Engine::ui::Rectangle>> _separator;
        int32_t _win_h;
        int32_t _win_w;
        int32_t _color;

    };
}


#endif //PONGSDL2_FIELDSEPARATOR_H
