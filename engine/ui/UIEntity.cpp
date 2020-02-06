//
// Created by jin on 2/2/20.
//

#include "UIEntity.h"

namespace Engine{
    namespace ui {
        void  UIEntity::font_size(uint16_t size){
            font().font_size(size);
        }

        uint16_t  UIEntity::font_size() {
            return font().font_size();
        }

        Font::TTFFont &UIEntity::font() {
            return EngineData::EngineData::instance().font();
        }

        int32_t UIEntity::window_width() {
            return EngineData::EngineData::instance().window().width();
        }

        int32_t window_height() {
            return EngineData::EngineData::instance().window().height();
        }
    }
}