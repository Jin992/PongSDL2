//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_ENGINEDATA_H
#define PONGSDL2_ENGINEDATA_H

#include <memory>
#include <core/SDLDestroyer.h>
#include <scene/SceneManager.h>
#include <window/Window.h>
#include <renderer/Renderer.h>
#include <TTFFont.h>


namespace Engine {
    namespace EngineData {

        typedef std::unique_ptr<_TTF_Font, SDLDestroyer>    engine_font_p;

        enum BuildState{
            Initialized,
            Uninitialized
        };

        class EngineData {
        public:
            EngineData(EngineData const &) = delete;
            void operator=(EngineData const &) = delete;

            static EngineData   &instance();
            Window::Window      &window();
            Renderer::Renderer  &renderer();
            Font::TTFFont       &font();
            Scene::SceneManager &sceneManager();

            /// retun true if EngineData has been inited
            BuildState    state() const;
            void          state(BuildState state);

        private:
            EngineData();

        private:
            BuildState          _state;
            Window::Window      _window;
            Renderer::Renderer  _renderer;
            Font::TTFFont       _font;
            Scene::SceneManager _scene_manager;
        };
    }
}


#endif //PONGSDL2_ENGINEDATA_H
