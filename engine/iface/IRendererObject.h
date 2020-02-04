//
// Created by root on 1/30/20.
//

#ifndef PONGSDL2_IRENDEREROBJECT_H
#define PONGSDL2_IRENDEREROBJECT_H

#include <memory>
#include <renderer/Renderer.h>
#include <iface/IEngineObject.h>

namespace Engine {
    class IRendererObject: public IEngineObject {
    public:
        virtual void render(Renderer::engine_renderer &) = 0;
        virtual void update() = 0;
        virtual ~IRendererObject() = default;
    };
}


#endif //PONGSDL2_IRENDEREROBJECT_H
