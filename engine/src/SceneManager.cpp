//
// Created by jin on 2/1/20.
//

#include <SceneManager.h>

namespace Engine {
    namespace Scene {
        SceneManager::SceneManager() : _init_scene(false) {}

        void SceneManager::startup_scene(const std::string &scene_name) {
            load_scene(scene_name);
            _init_scene = true;
        }

        void SceneManager::add_scene(const std::string &scene_name, engine_scene_ptr  scene) {
            auto search_res = _scenes.find(scene_name);
            if (search_res != _scenes.end())
                throw std::string(scene_name + " scene already exist");
            _scenes.insert(std::pair<std::string, engine_scene_ptr>{scene_name, scene});
        }

        void SceneManager::load_scene(const std::string &scene_name) {
            //if (!_init_scene)
            //    throw  std::string("Startup scene is not set, set startup scene.");
            auto scene = _scenes.find(scene_name);
            if (scene == _scenes.end())
                throw  std::string(scene_name + " scene doesn't exist");
            _cur_scene = scene->second;
        }

        uint64_t SceneManager::scenes_qnt() {
            return _scenes.size();
        }

        bool SceneManager::startup_scene() {
            return _init_scene;
        }

        engine_scene_ptr SceneManager::current_scene() {
            if (!_init_scene) {
                throw  std::string("Startup scene is not set, set startup scene.");
            }
            return _cur_scene;
        }
    }
}