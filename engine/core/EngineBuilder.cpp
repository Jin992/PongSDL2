//
// Created by jin on 2/1/20.
//

#include "EngineBuilder.h"

namespace Engine {
    namespace Builder {
        EngineBuilder::EngineBuilder() : _data(EngineData::EngineData::instance()), _render_fps(60) {}

        void EngineBuilder::setWindow(std::string const &title, uint32_t width, uint32_t height) {
            _data.window().init(title, height, width);
        }

        void EngineBuilder::setRendererFPS(uint16_t fps) {
            _render_fps = fps;
        }

        void EngineBuilder::setFont(const std::string &font_name, uint16_t font_size) {
            _data.font().set_font(font_name, font_size);
        }

        void EngineBuilder::addScene(std::string const & sceneName,  Scene::engine_scene_ptr scene) {
            _data.sceneManager().add_scene(sceneName, scene);
        }

        void EngineBuilder::loadScene(const std::string &sceneName) {
            EngineData::EngineData &data = EngineData::EngineData::instance();
            data.sceneManager().load_scene(sceneName);
        }

        void EngineBuilder::startup_scene(const std::string &sceneName) {
            _data.sceneManager().startup_scene(sceneName);
        }

        bool EngineBuilder::_sdl() {
            if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
                //err.err_msg("Failed to init SDL main module: " + std::string(SDL_GetError()));
                return false;
            }
            return true;
        }

        bool EngineBuilder::_ttf() {
            if (TTF_Init() < 0) {
                /// TODO check if SDL_GetError() correct for ttf errors
                //err.err_msg("Failed to initialize SDL_ttf module: " + std::string(SDL_GetError()));
                return false;
            }
            return true;
        }

        bool EngineBuilder::_init_sdl() {
            if (!_sdl()) return false;
            if (!_ttf()) return false;
            return true;
        }




        bool EngineBuilder::build() {
            _init_sdl();
            // Initialize SDL_Window
            _data.window().build();
            // Initialize SDL_Renderer
            _data.renderer().build(_data.window());
            // Initialize SDL_ttf
            _data.font().build();
            // Check scenes
            /*if (!_data.sceneManager().scenes_qnt()) {
                err.err_msg("There is no loaded scenes");
                return false;
            }
            // Check if startup scene
            if (!_data.sceneManager().startup_scene()) {
                err.err_msg("Startup scene is not set.");
                return false;
            }*/
            // Set EngineData as initialized
            _data.state(EngineData::BuildState::Initialized);
            return true;
        }
    }

}