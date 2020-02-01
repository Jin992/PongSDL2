//
// Created by jin on 2/1/20.
//

#include "EngineBuilder.h"


#include <iostream>

namespace Engine {
    namespace Builder {
        EngineBuilder::EngineBuilder() : _window_width(640), _window_height(480), _render_fps(60) {}

        void EngineBuilder::setWindow(std::string const &title, uint32_t width, uint32_t height) {
            _window_title = title;
            _window_width = width;
            _window_height = height;
        }

        void EngineBuilder::setRendererFPS(uint16_t fps) {
            _render_fps = fps;
        }

        void EngineBuilder::addScene(std::string const & sceneName, Scene::engine_scene_p scene, std::string &err) {
            EngineData::EngineData &data = EngineData::EngineData::instance();
            data.sceneManager().add_scene(sceneName, scene, err);
        }

        void EngineBuilder::loadScene(const std::string &sceneName, std::string &err) {
            EngineData::EngineData &data = EngineData::EngineData::instance();
            data.sceneManager().load_scene(sceneName, err);
        }

        void EngineBuilder::startup_scene(const std::string &sceneName, std::string &err) {
            EngineData::EngineData &data = EngineData::EngineData::instance();
            data.sceneManager().startup_scene(sceneName, err);
        }

        bool EngineBuilder::_sdl() {
            if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
                std::cerr << "Failed to init SDL main module: " << SDL_GetError() << std::endl;
                return false;
            }
            return true;
        }

        bool EngineBuilder::_ttf() {
            if (TTF_Init() < 0) {
                std::cerr << "Failed to initialize SDL_ttf module: " << SDL_GetError() << std::endl;
                return false;
            }
            return true;
        }

        bool EngineBuilder::_init_sdl() {
            if (!_sdl()) return false;
            if (!_ttf()) return false;
            return true;
        }

        bool EngineBuilder::_build_window(Engine::EngineData::EngineData &data) {
            data.window() = EngineData::engine_window_p(
                SDL_CreateWindow(_window_title.c_str(),
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 _window_width,
                                 _window_height,
                                 SDL_WINDOW_SHOWN));
            if (data.window() == nullptr) {
                std::cerr << "SDL failed to create window: "
                          << SDL_GetError() << std::endl;
                return false;
            }
            return true;
        }

        bool EngineBuilder::_build_renderer(Engine::EngineData::EngineData &data) {
            data.renderer() = EngineData::engine_renderer_p(
                    SDL_CreateRenderer(data.window().get(),
                                   -1,
                                   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
            if (data.renderer() == nullptr) {
                std::cerr << "SDL failed to create renderer: "
                          << SDL_GetError() << std::endl;
            }
            return true;
        }

        bool EngineBuilder::_build_font(Engine::EngineData::EngineData &data) {
            /// TODO set propper path to fonts
            data.font() = EngineData::engine_font_p(
                    TTF_OpenFont("../fonts/DejaVuSansMono-Bold.ttf", 28));
            if (data.font() == nullptr) {
                std::cerr << "SDL failed to load ttf font: "
                          << TTF_GetError() << std::endl;
                return false;
            }
            return true;
        }

        bool EngineBuilder::build() {
            if (!_init_sdl()) return false;
            EngineData::EngineData &data = EngineData::EngineData::instance();
            // Initialize SDL_Window
            if (!_build_window(data)) return false;
            // Initialize SDL_Renderer
            if (!_build_renderer(data)) return false;
            // Initialize SDL_ttf
            if (!_build_font(data)) return false;
            // Check scenes
            if (!data.sceneManager().scenes_qnt()) {
                std::cerr << "There is no loaded scenes";
                return false;
            }
            // Check if startup scene
            if (!data.sceneManager().startup_scene()) {
                std::cerr << "Startup scene is not set." << std::endl;
                return false;
            }
            // Set EngineData as initialized
            data.state(EngineData::BuildState::Initialized);
            return true;
        }
    }

}