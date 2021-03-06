//
// Created by root on 1/30/20.
//

#ifndef PONGSDL2_IRENDEREROBJECT_H
#define PONGSDL2_IRENDEREROBJECT_H

#include <memory>
#include "Renderer.h"

namespace Engine {
    class IRendererObject {
    public:
        virtual void render(Renderer::engine_renderer &) = 0;
        virtual void update(double) {}
        virtual ~IRendererObject() = default;
    };
}


#endif //PONGSDL2_IRENDEREROBJECT_H
