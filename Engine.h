//
// Created by root on 1/30/20.
//

#ifndef PONGSDL2_ENGINE_H
#define PONGSDL2_ENGINE_H

#include <memory>
#include "IScene.h"

struct SDL_Window;
struct SDL_Renderer;
struct _TTF_Font;

namespace PingPong {

    typedef std::shared_ptr<SDL_Window>   sdl_window_ptr_t;
    typedef std::shared_ptr<SDL_Renderer> sdl_renderer_ptr_t;
    typedef std::shared_ptr<_TTF_Font>    sdl_ttf_font_ptr_t;

    class Engine {
    public:
        Engine(std::string const &title, uint32_t width, uint32_t height);
        Engine(Engine const &) = delete;
        Engine(Engine const &&) = delete;
        Engine &operator=(Engine const &) = delete;
        Engine &operator=(Engine const &&) = delete;
        ~Engine() = default;

        /// Engine initialize function
        bool init();
        /// start game loop
        void run();

    private:
        std::string             _title;
        uint32_t                _width;
        uint32_t                _height;
        sdl_window_ptr_t        _window;
        sdl_renderer_ptr_t      _renderer;
        sdl_ttf_font_ptr_t      _font;
        std::unique_ptr<IScene> _scene;
    };
}

#endif //PONGSDL2_ENGINE_H
