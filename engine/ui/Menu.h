//
// Created by jin on 2/3/20.
//

#ifndef PONGSDL2_MENU_H
#define PONGSDL2_MENU_H

#include <ui/Button.h>
#include <iface/IRendererObject.h>
#include <iface/IPressObject.h>
#include <memory>

namespace Engine {
    namespace ui {

    class Menu: public UIEntity, public IPressObject {
    public:
        Menu(int32_t x, int32_t y);

        void setItemPadding(uint16_t padding);

        void    add_button(std::string const & name, engine_key_hdl down, engine_key_hdl up);
        void    nextIndex();
        void    prevIndex();
        std::shared_ptr<Button>selected();
        void    render(Renderer::engine_renderer &renderer) override;
        void    update() override;

    private:
        std::vector<std::pair<std::string, std::shared_ptr<Button>>> _buttons;
        int32_t                                     _item_pos;
        uint16_t                                    _padding;
        int32_t                                     _active_index;
        };
    }
}



#endif //PONGSDL2_MENU_H
