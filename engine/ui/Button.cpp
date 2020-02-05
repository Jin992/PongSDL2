//
// Created by jin on 2/3/20.
//

#include "Button.h"

namespace Engine {
    namespace ui {
        Button::Button():Label() {
            type(IEngineObject::Pressable);

        }

        Button::~Button(){};

        Button::Button(std::string const &btn_text, int32_t color, int32_t x, int32_t y)
        : Label(btn_text, color, x, y){
            type(IEngineObject::Pressable);

        }

    }
}