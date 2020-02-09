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

            void addScene(std::string const &,  Scene::engine_scene_ptr scene);
            void loadScene(std::string const&);
            void startup_scene(std::string const &);
            bool build();

        private:
            void _init_sdl();
            void _sdl();
            void _ttf();

        private:
            EngineData::EngineData  &_data;
            uint16_t                _render_fps;

        };
    }
}



#endif //PONGSDL2_ENGINEBUILDER_H
