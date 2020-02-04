//
// Created by jin on 2/3/20.
//

#include "Label.h"
namespace Engine {
    namespace ui {
        Label::Label() : _btn_text("Undefined") {
            entity_color(0xffffff);
            type(IEngineObject::Static);
            init(_btn_text, entity_color(), 0, 0);
        }

        Label::Label(std::string const &btn_text, int32_t color, int32_t x, int32_t y) {
            type(IEngineObject::Static);
            init(btn_text, color, x, y);
        }


        void Label::init(std::string const &btn_text, int32_t color, int32_t x, int32_t y) {
            Engine::Error::EngineError err;
            _btn_text = btn_text;
            entity_color(color);
            init_entity(x, y);

            _texture = font().createText(_btn_text, entity_color(), err);
        }

        void Label::color(int32_t new_color) {
            Engine::Error::EngineError err;
            entity_color(new_color);
            _texture = font().createText(_btn_text, new_color, err);
        }

        int32_t Label::color() const {
            return entity_color();
        }

        void Label::update() {

        }

    }
}