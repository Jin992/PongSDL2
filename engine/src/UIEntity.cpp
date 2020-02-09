//
// Created by jin on 2/2/20.
//

#include <UIEntity.h>

namespace Engine{
    namespace ui {
        UIEntity::UIEntity(){
            set_font("../fonts/ARCADECLASSIC.ttf", 32);
            build();
        }

        int32_t UIEntity::window_width() {
            return EngineData::EngineData::instance().window().width();
        }

        int32_t window_height() {
            return EngineData::EngineData::instance().window().height();
        }
    }
}