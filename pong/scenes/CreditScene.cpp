//
// Created by jin on 2/5/20.
//

#include "CreditScene.h"

namespace PongGame {

    CreditScene::CreditScene()
    : _title(std::make_shared<Engine::ui::Label>()), _info(std::make_shared<Engine::ui::Label>())
    {
        _title->font_size(45);
        _title->init(std::string("Created     by     Yevhen     Arteshchuk"), 0xff4c4c, 400, 100);
        add_entity(_title);

        _info->font_size(25);
        _info->init(std::string("Press    ESC    to    return     main     menu"), 0xff4c4c, 400, 390);
        add_entity(_info);

    }

    void CreditScene::sceneEvent(SDL_Event &ev) {
        for_each_entity([&ev](Engine::entity::engine_entity_ptr entity) {
            if (entity->type() != Engine::entity::Pressable) {}
            if(ev.type == SDL_KEYDOWN) {
                switch (ev.key.keysym.sym ){
                    case SDLK_ESCAPE:
                        Engine::EngineData::EngineData::instance().sceneManager().load_scene("MainMenu");
                        break;

                    default:
                        break;
                }
            }
        });
    }

    void CreditScene::render(Engine::Renderer::engine_renderer &renderer) {
        for_each_entity([&renderer](Engine::entity::engine_entity_ptr entity) {
            entity->render(renderer);
        });
    }

    void CreditScene::update() {}
}