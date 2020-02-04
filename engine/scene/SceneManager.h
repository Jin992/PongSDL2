//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_SCENEMANAGER_H
#define PONGSDL2_SCENEMANAGER_H

#include <map>
#include "Scene.h"
#include <error/EngineError.h>

namespace Engine {
    namespace Scene {
        class SceneManager {
        public:
            SceneManager();

            void            startup_scene(std::string const &scene_name, std::string &err);
            void            add_scene(std::string const &scene_name, engine_scene_ptr scene, std::string &err);
            void            load_scene(std::string const &, std::string &);
            uint64_t        scenes_qnt();
            bool            startup_scene();
            engine_scene_ptr current_scene(Error::EngineError &);

        private:
            std::map<std::string, engine_scene_ptr>  _scenes;
            engine_scene_ptr                         _cur_scene;
            bool                                     _init_scene;
        };
    }
}
#endif //PONGSDL2_SCENEMANAGER_H