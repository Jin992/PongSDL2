//
// Created by jin on 2/2/20.
//

#ifndef PONGSDL2_UIENTITY_H
#define PONGSDL2_UIENTITY_H


#include "EngineData.h"
#include "Entity.h"
#include "TTFFont.h"

namespace Engine {
    namespace ui {

        typedef std::unique_ptr<SDL_Surface, SDLDestroyer>  engine_sufrace;
        typedef std::shared_ptr<SDL_Texture>  engine_texture;

    class UIEntity: public entity::Entity, public Font::TTFFont {
        public:
            UIEntity();

            virtual ~UIEntity() = default;

        protected:

            int32_t window_width();
            int32_t window_height();
        };
    }
}



#endif //PONGSDL2_UIENTITY_H
