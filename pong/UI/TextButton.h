//
// Created by jin on 2/2/20.
//

#ifndef PONGSDL2_TEXTBUTTON_H
#define PONGSDL2_TEXTBUTTON_H

#include <ui/Button.h>

namespace PongGame {
    namespace ui {
        class TextButton: public Engine::ui::Button {
        public:
            TextButton();
            TextButton(std::string const &btn_text, int32_t color, int32_t x, int32_t y);
            void init(std::string const &btn_text, int32_t color, int32_t x, int32_t y);
            void update() override;
            void onClickDown(SDL_KeyboardEvent &event) override {if (event.timestamp) {}}
            void onClickUp(SDL_KeyboardEvent &event) override {if (event.timestamp) {}}
            void onKeyPressDown(SDL_KeyboardEvent &event) override {if (event.timestamp) {}}
            void onKeyPressUp(SDL_KeyboardEvent &event) override {if (event.timestamp) {}}

        private:
            std::string                _btn_text;
            uint32_t                   _color;
        };
    }
}



#endif //PONGSDL2_TEXTBUTTON_H
