//
// Created by root on 1/30/20.
//

#ifndef PONGSDL2_IRENDEREROBJECT_H
#define PONGSDL2_IRENDEREROBJECT_H

#include <memory>

class SDL_Renderer;

namespace Engine {
    class IRendererObject {
    public:
        virtual void render(std::unique_ptr<SDL_Renderer> &) = 0;
        virtual void update() = 0;
    };
}


#endif //PONGSDL2_IRENDEREROBJECT_H
