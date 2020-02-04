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

            std::string text() const {
                return _btn_text;
            }

        private:
            std::string _btn_text;
            int32_t _color;
        };

    }

}

#endif //PONGSDL2_LABEL_H
