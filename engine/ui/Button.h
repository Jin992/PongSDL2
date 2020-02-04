//
// Created by jin on 2/3/20.
//

#ifndef PONGSDL2_BUTTON_H
#define PONGSDL2_BUTTON_H

#include "Label.h"
#include <iface/IPressObject.h>

namespace Engine {
    namespace ui {
        class Button : public ui::Label, public IPressObject {
        public:
            Button();
            Button(std::string const &btn_text, int32_t color, int32_t x, int32_t y);
            ~Button() override;
        };
    }
}


#endif //PONGSDL2_BUTTON_H
