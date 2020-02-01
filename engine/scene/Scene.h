//
// Created by root on 1/30/20.
//

#ifndef PONGSDL2_SCENE_H
#define PONGSDL2_SCENE_H

#include <memory>
#include "../iface/IRendererObject.h"

// Forward declarations
struct SDL_KeyboardEvent;

namespace Engine {
    namespace Scene {
        class Scene;

        typedef std::shared_ptr<Scene> engine_scene_p;

        class Scene : public IRendererObject {
        public:
            void render(std::unique_ptr<SDL_Renderer> &) override;
            void update() override;
            virtual void key_down(SDL_KeyboardEvent &event);
            virtual void key_up(SDL_KeyboardEvent &event);
        };
    }
}


#endif //PONGSDL2_SCENE_H
