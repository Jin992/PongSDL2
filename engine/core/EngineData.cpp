//
// Created by jin on 2/1/20.
//

#include "EngineData.h"

namespace Engine{
    namespace EngineData {
        EngineData::EngineData(): _state(BuildState::Uninitialized)
        {}

        EngineData &EngineData::instance() {
            static EngineData INSTANCE;
            return INSTANCE;
        }

        Window::Window &EngineData::window() {
            return _window;
        }

        Renderer::Renderer &EngineData::renderer() {
            return _renderer;
        }

        Font::TTFFont &EngineData::font() {
            return _font;
        }

        Scene::SceneManager &EngineData::sceneManager() {
            return _scene_manager;
        }

        BuildState EngineData::state() const {
            return _state;
        }

        void EngineData::state(BuildState state) {
            _state = state;
        }

        bool EngineData::engine_status() {
            return _engine_status;
        }

        void EngineData::engine_status(bool status) {
            _engine_status = status;
        }

    }}