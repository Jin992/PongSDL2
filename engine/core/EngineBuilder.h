//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_ENGINEBUILDER_H
#define PONGSDL2_ENGINEBUILDER_H

#include <string>
#include "EngineData.h"

namespace Engine {
    namespace Builder {
        class EngineBuilder {
        public:
            EngineBuilder();

            void setWindow(std::string const &title, uint32_t width, uint32_t height);
            void setRendererFPS(uint16_t fps);

            void addScene(std::string const &, Scene::engine_scene_p, std::string &);
            void loadScene(std::string const&, std::string &);
            void startup_scene(std::string const &, std::string &);


            bool build();

        private:
            bool _init_sdl();
            bool _sdl();
            bool _ttf();
            bool _build_window(EngineData::EngineData &data);
            bool _build_renderer(EngineData::EngineData &data);
            bool _build_font(EngineData::EngineData &data);

        private:
            std::string _window_title;
            uint32_t    _window_width;
            uint32_t    _window_height;
            uint16_t    _render_fps;

        };
    }
}



#endif //PONGSDL2_ENGINEBUILDER_H
