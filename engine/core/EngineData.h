//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_ENGINEDATA_H
#define PONGSDL2_ENGINEDATA_H

#include <memory>
#include "SDLDestroyer.h"
#include "../scene/SceneManager.h"

struct SDL_Window;
struct _TTF_Font;

namespace Engine {
    namespace EngineData {
        typedef std::unique_ptr<SDL_Window, SDLDestroyer>   engine_window_p;
        typedef std::unique_ptr<SDL_Renderer, SDLDestroyer> engine_renderer_p;
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
            engine_window_p     &window();
            engine_renderer_p   &renderer();
            engine_font_p       &font();
            Scene::SceneManager &sceneManager();

            /// retun true if EngineData has been inited
            BuildState    state() const;
            void          state(BuildState state);

        private:
            EngineData();

        private:
            BuildState          _state;
            engine_window_p     _window;
            engine_renderer_p   _renderer;
            engine_font_p       _font;
            Scene::SceneManager _scene_manager;
        };
    }
}


#endif //PONGSDL2_ENGINEDATA_H
