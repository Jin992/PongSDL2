//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_RENDERER_H
#define PONGSDL2_RENDERER_H

#include "SDLDestroyer.h"
#include <memory>

struct SDL_Renderer;

namespace Engine {

    namespace Window {
        class Window;
    }

    namespace Renderer {
        typedef std::unique_ptr<SDL_Renderer, SDLDestroyer> engine_renderer;
        class Renderer {
        public:
            Renderer() = default;
            Renderer(Renderer const &) = delete;
            Renderer operator=(Renderer const &) = delete;
            explicit operator bool() const;

            engine_renderer &get();
            void build(Window::Window &);

        private:
            engine_renderer _renderer;

        };
    }
}



#endif //PONGSDL2_RENDERER_H
