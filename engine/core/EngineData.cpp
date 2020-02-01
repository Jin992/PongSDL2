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

        engine_window_p &EngineData::window() {
            return _window;
        }

        engine_renderer_p &EngineData::renderer() {
            return _renderer;
        }

        engine_font_p &EngineData::font() {
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

    }}