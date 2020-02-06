//
// Created by jin on 2/3/20.
//

#include "Menu.h"
namespace Engine {
    namespace ui {
        Menu::Menu(int32_t x, int32_t y)
        : _item_pos(0), _active_index(0) {
            set_x(x);
            set_y(y);
            type(entity::Pressable);
            setOnKeyPressDown_hdl([this](SDL_KeyboardEvent &ev) {
                selected().onKeyPressDown(ev);
            });

            setOnKeyPressUp_hdl([](SDL_KeyboardEvent &ev) {
                if (ev.timestamp){}

            });
        }

        void Menu::setItemPadding(uint16_t padding) {
            _padding = padding;
        }

        void Menu::add_button(std::string const & name, engine_key_hdl down, engine_key_hdl up){
            auto btn = Button(name, -1, x(), y() + _item_pos);
            _item_pos += _padding;
            btn.setOnKeyPressUp_hdl(up);
            btn.setOnKeyPressDown_hdl(down);
            _buttons.push_back({name, btn});
            if (_buttons[_active_index].second.color() != 0x4c4cff)
                _buttons[_active_index].second.color(0x4c4cff);
        }

        void Menu::nextIndex() {
            // change color of current item to default
            _buttons[_active_index].second.color(-1);
            // check if active index in vector range
            if (++_active_index  >= (int32_t)_buttons.size())
            _active_index = 0;
            // change color of next item to select color
            _buttons[_active_index].second.color(0x4c4cff);
        }

        void Menu::prevIndex() {
            // change color of current item to default
            _buttons[_active_index].second.color(-1);
            // check if active index in vector range
            if (--_active_index < 0)
                _active_index = _buttons.size() - 1;
            // change color of previous item to select color
            _buttons[_active_index].second.color(0x4c4cff);

        }

        Button &Menu::selected() {
            return _buttons[_active_index].second;
        }

        void Menu::render(Renderer::engine_renderer &renderer) {
            for (auto it : _buttons)
                it.second.render(renderer);
        }

        void Menu::update() {}
    };
}