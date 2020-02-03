//
// Created by jin on 2/2/20.
//

#include "TextButton.h"

namespace PongGame {
    namespace ui {
        TextButton::TextButton():  _btn_text("Undefined"), _color(-1)
        {

            init(_btn_text, _color, 0, 0);
        }

        TextButton::TextButton(std::string const &btn_text, int32_t color, int32_t x, int32_t y) {
            init(btn_text, color, x, y);
        }


        void TextButton::init(std::string const &btn_text, int32_t color, int32_t x, int32_t y) {
            Engine::Error::EngineError err;
            _btn_text = btn_text;
            _color = color;
            init_entity(x,y);

            texture(font().createText(_btn_text, _color, err));
        }

        void TextButton::update() {

        }

    }
}