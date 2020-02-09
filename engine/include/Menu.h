//
// Created by jin on 2/3/20.
//

#ifndef PONGSDL2_MENU_H
#define PONGSDL2_MENU_H

#include "Button.h"
#include "IRendererObject.h"
#include "IPressObject.h"
#include <memory>

namespace Engine {
    namespace ui {

    class Menu: public UIEntity, public IPressObject {
    public:
        Menu(int32_t x, int32_t y);

        void setItemPadding(uint16_t padding);

        void                    add_button(std::string const &, engine_key_hdl, engine_key_hdl);
        void                    nextIndex();
        void                    prevIndex();
        std::shared_ptr<Button> selected();
        void                    render(Renderer::engine_renderer &) override;
        void                    update(double) override;
        void                    set_active_color(int32_t);
        void                    set_color(int32_t);

    private:
        std::vector<std::pair<std::string, std::shared_ptr<Button>>> _buttons;
        int32_t                                                     _item_pos;
        uint16_t                                                    _padding;
        int32_t                                                     _active_index;
        int32_t                                                     _active_color;
        int32_t                                                     _color;
        };
    }
}



#endif //PONGSDL2_MENU_H
