//
// Created by jin on 2/1/20.
//

#include "Renderer.h"
#include <window/Window.h>

namespace Engine {
    namespace Renderer {
        engine_renderer &Renderer::get() {
            return _renderer;
        }

        void Renderer::build(Window::Window &window, Error::EngineError &err) {
            _renderer =engine_renderer(SDL_CreateRenderer(window.get().get(),
                                       -1,
                                       SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
            if (_renderer == nullptr)
                err.err_msg("SDL failed to create renderer: " + std::string(SDL_GetError()));
        }

        Renderer::operator bool() const {
            return !(_renderer == nullptr);
        }
    }
}