//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_ENTITY_H
#define PONGSDL2_ENTITY_H

#include "../iface/IRendererObject.h"

namespace Engine {
    class Entity : public IRendererObject {
    public:
        void render(std::unique_ptr<SDL_Renderer> &) override;
        void update() override ;
    };
}

#endif //PONGSDL2_ENTITY_H
