//
// Created by jin on 2/1/20.
//

#include "SceneManager.h"

namespace Engine {
    namespace Scene {
        SceneManager::SceneManager() : _init_scene(false) {}

        void SceneManager::startup_scene(const std::string &scene_name, std::string &err) {
            load_scene(scene_name, err);
            if (err.empty()) _init_scene = true;
        }

        void SceneManager::add_scene(const std::string &scene_name, engine_scene_ptr  scene, std::string &err) {
            auto search_res = _scenes.find(scene_name);
            if (search_res != _scenes.end()) {
                err = std::string(scene_name + " scene already exist");
                return;
            }
            _scenes.insert(std::pair<std::string, engine_scene_ptr>{scene_name, scene});
        }

        void SceneManager::load_scene(const std::string &scene_name, std::string &err) {
            /*if (!_init_scene) {
                err = std::string("Startup scene is not set, set startup scene.");
                return;
            }*/
            auto scene = _scenes.find(scene_name);
            if (scene == _scenes.end()) {
                err = std::string(scene_name + " scene doesn't exist");
                return;
            }
            //std::cerr << "Scene has been loaded" << std::endl;
            _cur_scene = scene->second;
        }

        uint64_t SceneManager::scenes_qnt() {
            return _scenes.size();
        }

        bool SceneManager::startup_scene() {
            return _init_scene;
        }

        engine_scene_ptr SceneManager::current_scene(Error::EngineError &err) {
            if (!_init_scene) {
                err.err_msg("Startup scene is not set, set startup scene.");
            }
            return _cur_scene;
        }
    }
}