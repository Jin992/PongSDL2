//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_ENGINEBUILDER_H
#define PONGSDL2_ENGINEBUILDER_H

#include <string>
#include <core/EngineData.h>
#include <error/EngineError.h>

namespace Engine {
    namespace Builder {
        class EngineBuilder {
        public:
            EngineBuilder();

            void setWindow(std::string const &title, uint32_t width, uint32_t height);
            void setRendererFPS(uint16_t fps);
            void setFont(std::string const &, uint16_t);

            void addScene(std::string const &,  Scene::engine_scene_ptr scene, std::string &);
            void loadScene(std::string const&, std::string &);
            void startup_scene(std::string const &, std::string &);
            bool build(Error::EngineError &err);

        private:
            bool _init_sdl(Error::EngineError &);
            bool _sdl(Error::EngineError &);
            bool _ttf(Error::EngineError &);

        private:
            EngineData::EngineData &_data;
            uint16_t    _render_fps;

        };
    }
}



#endif //PONGSDL2_ENGINEBUILDER_H
