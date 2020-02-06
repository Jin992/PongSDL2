//
// Created by jin on 2/1/20.
//

#include "Window.h"

namespace Engine {
    namespace Window {
        Window::Window()
        : _title("Unnamed"), _height(480), _width(640)
        {}

        void Window::init(const std::string &title, uint32_t height, uint32_t width) {
            _title = title;
            _height = height;
            _width = width;
        }

        void Window::build() {
            _window = engine_window(
                    SDL_CreateWindow(_title.c_str(),
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,
                                     _width,
                                     _height,
                                     SDL_WINDOW_SHOWN));
            if (_window == nullptr)
                throw std::string("SDL failed to create window: " + std::string(SDL_GetError()));
        }

        uint32_t Window::height() const {
            return _height;
        }

        uint32_t Window::width() const {
            return _width;
        }

        std::string Window::title() const {
            return _title;
        }

        engine_window &Window::get() {
            return _window;
        }

        Window::operator bool() const {
            return !(_window == nullptr);
        }
    }
}