//
// Created by jin on 2/3/20.
//

#include "Label.h"

namespace Engine {
    namespace ui {
        Label::Label() : _text("Undefined"), _color(0xffffff){
            type(entity::Static);
        }

        Label::Label(std::string const &text, int32_t color, int32_t x, int32_t y)
        : _text(text), _color(color) {
            type(entity::Static);
            init(_text, color, x, y);
        }


        void Label::init(std::string const &btn_text, int32_t color, int32_t x, int32_t y) {
            _text = btn_text;
            _color = color;
            set_x(x);
            set_y(y);

            _texture = createText(_text, _color);
        }

        void Label::color(int32_t new_color) {
            _color = new_color;
            _texture = createText(_text, new_color);
        }

        int32_t Label::color() const {
            return _color;
        }

        void Label::render(Renderer::engine_renderer &renderer)  {
            SDL_Rect rect{x(), y(), 0, 0};
            SDL_QueryTexture(_texture.get(), nullptr, nullptr, &rect.w, &rect.h);
            rect.x -= rect.w / 2;
            SDL_RenderCopy(renderer.get(), _texture.get(), nullptr, &rect);
        }

        std::string Label::text() const {
            return _text;
        }

        void Label::set_text(std::string const &str) {
            _text = str;
            _reinit();
        }

        void Label::update(double) {}

        void Label::_reinit() {
            _texture = createText(_text, _color);
        }

    }
}