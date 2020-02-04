//
// Created by jin on 2/3/20.
//

#ifndef PONGSDL2_LABEL_H
#define PONGSDL2_LABEL_H

#include <ui/UIEntity.h>

namespace Engine {
    namespace ui {
        class Label : public UIEntity {
        public:
            Label();
            Label(std::string const &btn_text, int32_t color, int32_t x, int32_t y);
            void init(std::string const &btn_text, int32_t color, int32_t x, int32_t y);
            void update() override;
            void color(int32_t new_color);
            int32_t color() const;

            void render(Renderer::engine_renderer &renderer) override {
                SDL_Rect rect{x(), y(), 0, 0};
                SDL_QueryTexture(_texture.get(), nullptr, nullptr, &rect.w, &rect.h);
                rect.x -= rect.w / 2;
                SDL_RenderCopy(renderer.get(), _texture.get(), nullptr, &rect);
            }

            std::string text() const {
                return _btn_text;
            }

        private:
            std::string     _btn_text;
            engine_texture  _texture;
        };

    }

}

#endif //PONGSDL2_LABEL_H
