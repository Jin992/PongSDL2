//
// Created by jin on 2/3/20.
//

#ifndef PONGSDL2_LABEL_H
#define PONGSDL2_LABEL_H

#include <ui/UIEntity.h>
#include <error/EngineError.h>

namespace Engine {
    namespace ui {
        class Label : public UIEntity {
        public:
            Label();
            Label(std::string const &btn_text, int32_t color, int32_t x, int32_t y);
            void            init(std::string const &btn_text, int32_t color, int32_t x, int32_t y);
            void            update() override;
            void            color(int32_t new_color);
            int32_t         color() const;

            void            render(Renderer::engine_renderer &renderer) override;
            std::string     text() const;
            void            set_text(std::string const &str);

        private:
            void            _reinit();

        private:
            std::string     _text;
            engine_texture  _texture;
            uint32_t        _color;
        };

    }

}

#endif //PONGSDL2_LABEL_H
