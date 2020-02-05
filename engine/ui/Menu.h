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
        Menu(int32_t x, int32_t y): _item_pos(0), _active_index(0) {
            init_entity(x, y);
            type(IEngineObject::Pressable);
            setOnKeyPressDown_hdl([this](SDL_KeyboardEvent &ev) {
               selected().onKeyPressDown(ev);
            });

            setOnKeyPressUp_hdl([](SDL_KeyboardEvent &ev) {
                if (ev.timestamp){}

            });
        }

        void setItemPadding(uint16_t padding) {
            _padding = padding;
        }

        void add_button(std::string const & name, engine_key_hdl down, engine_key_hdl up){
            auto btn = Button(name, -1, x(), y() + _item_pos);
            _item_pos += _padding;
            btn.setOnKeyPressUp_hdl(up);
            btn.setOnKeyPressDown_hdl(down);
            _buttons.push_back({name, btn});
            if (_buttons[_active_index].second.color() != 0x4c4cff)
                _buttons[_active_index].second.color(0x4c4cff);
        }

        void nextIndex() {
            // change color of current item to default
            _buttons[_active_index].second.color(-1);
            // check if active index in vector range
            if (++_active_index  >= (int32_t)_buttons.size())
                _active_index = 0;
            // change color of next item to select color
            _buttons[_active_index].second.color(0x4c4cff);
        }

        void prevIndex() {
            // change color of current item to default
            _buttons[_active_index].second.color(-1);
            // check if active index in vector range
            if (--_active_index < 0)
                _active_index = _buttons.size() - 1;
            // change color of previous item to select color
            _buttons[_active_index].second.color(0x4c4cff);

        }

        Button &selected() {
            return _buttons[_active_index].second;
        }

        void render(Renderer::engine_renderer &renderer) override {
            for (auto it : _buttons)
                it.second.render(renderer);
        }

        void update() override {}

    private:
        std::vector<std::pair<std::string, Button>> _buttons;
        int32_t  _item_pos;
        uint16_t _padding;
        int32_t _active_index;
        };
    }
}



#endif //PONGSDL2_MENU_H
