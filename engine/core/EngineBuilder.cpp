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

        void EngineBuilder::addScene(std::string const & sceneName,  Scene::engine_scene_ptr scene, std::string &err) {
            _data.sceneManager().add_scene(sceneName, scene, err);
        }

        void EngineBuilder::loadScene(const std::string &sceneName, std::string &err) {
            EngineData::EngineData &data = EngineData::EngineData::instance();
            data.sceneManager().load_scene(sceneName, err);
        }

        void EngineBuilder::startup_scene(const std::string &sceneName, std::string &err) {
            _data.sceneManager().startup_scene(sceneName, err);
        }

        bool EngineBuilder::_sdl(Error::EngineError &err) {
            if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
                err.err_msg("Failed to init SDL main module: " + std::string(SDL_GetError()));
                return false;
            }
            return true;
        }

        bool EngineBuilder::_ttf(Error::EngineError &err) {
            if (TTF_Init() < 0) {
                /// TODO check if SDL_GetError() correct for ttf errors
                err.err_msg("Failed to initialize SDL_ttf module: " + std::string(SDL_GetError()));
                return false;
            }
            return true;
        }

        bool EngineBuilder::_init_sdl(Error::EngineError &err) {
            if (!_sdl(err)) return false;
            if (!_ttf(err)) return false;
            return true;
        }




        bool EngineBuilder::build(Error::EngineError &err) {
            _init_sdl(err);
            // Initialize SDL_Window
            _data.window().build(err);
            if (err) return false;
            // Initialize SDL_Renderer
            _data.renderer().build(_data.window(), err);
            if (err) return false;
            // Initialize SDL_ttf
            _data.font().build(err);
            if (err) return false;
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