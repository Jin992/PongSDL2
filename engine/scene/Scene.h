//
// Created by root on 1/30/20.
//

#ifndef PONGSDL2_SCENE_H
#define PONGSDL2_SCENE_H

#include <memory>
#include <iface/IRendererObject.h>
#include <renderer/Renderer.h>
#include <iostream>
#include <entity/Entity.h>
#include <vector>

// Forward declarations
struct SDL_KeyboardEvent;

namespace Engine {
    namespace Scene {
        class Scene;

        typedef std::shared_ptr<Scene> engine_scene_ptr;

        class Scene : public IRendererObject {
        public:
            virtual  ~Scene() = default;

        protected:
            void add_entity(entity::engine_entity_ptr entity){
                _entity_vec.push_back(entity);
            }

            void for_each_entity(std::function<void(entity::engine_entity_ptr entity)> func) {
                for (auto it : _entity_vec)
                    func(it);
            }

        private:
            engine_scene_ptr _scene;
            std::vector<entity::engine_entity_ptr> _entity_vec;
        };
    }
}


#endif //PONGSDL2_SCENE_H
