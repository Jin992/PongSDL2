//
// Created by jin on 2/2/20.
//

#ifndef PONGSDL2_UIENTITY_H
#define PONGSDL2_UIENTITY_H


#include <core/EngineData.h>
#include <entity/Entity.h>

namespace Engine {
    namespace ui {

        typedef std::unique_ptr<SDL_Surface, SDLDestroyer>  engine_sufrace;
        typedef std::shared_ptr<SDL_Texture>  engine_texture;

    class UIEntity: public entity::Entity {
        public:
            UIEntity() = default;

            virtual ~UIEntity() = default;

        void  font_size(uint16_t size);
        uint16_t  font_size();

        protected:
            Font::TTFFont &font();
            int32_t window_width();
            int32_t window_height();
        };
    }
}



#endif //PONGSDL2_UIENTITY_H
