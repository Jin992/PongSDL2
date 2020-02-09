//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_WINDOW_H
#define PONGSDL2_WINDOW_H

#include <string>
#include <core/SDLDestroyer.h>
#include <memory>

struct SDL_Window;

namespace Engine {
    namespace Window {
        #define WIN_DEFAULT_H 480
        #define WIN_DEFAULT_W 640
        typedef std::unique_ptr<SDL_Window, SDLDestroyer> engine_window;

        class Window {
        public:
            Window();

            Window(Window const &) = delete;
            Window operator=(Window const &) = delete;
            explicit operator bool() const;

            void            init(std::string const &title, uint32_t height=WIN_DEFAULT_H, uint32_t width=WIN_DEFAULT_W);
            void            build();
            uint32_t        height() const;
            uint32_t        width() const;
            std::string     title() const;
            engine_window   &get();

        private:
            engine_window   _window;
            std::string     _title;
            uint32_t        _height;
            uint32_t        _width;
        };
    }
}


#endif //PONGSDL2_WINDOW_H
