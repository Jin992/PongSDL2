//
// Created by jin on 2/2/20.
//

#ifndef PONGSDL2_BUTTON_H
#define PONGSDL2_BUTTON_H


#include <core/EngineData.h>
#include <entity/Entity.h>

namespace Engine {
    namespace ui {

        typedef std::unique_ptr<SDL_Surface, SDLDestroyer>  engine_sufrace;
        typedef std::shared_ptr<SDL_Texture>  engine_texture;

    class Button: public entity::Entity {
        public:
            Button():_data(EngineData::EngineData::instance()) {}

        protected:
            Font::TTFFont &font() { return _data.font();}
            int32_t window_width() { return _data.window().width();}
            int32_t window_height() {return _data.window().height();}


        private:
            EngineData::EngineData &_data;
        };
    }
}



#endif //PONGSDL2_BUTTON_H
