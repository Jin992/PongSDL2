//
// Created by jin on 2/1/20.
//

#include <SDL_events.h>
#include <core/EngineData.h>
#include "MainMenuScene.h"

namespace PongGame {
    MainMenuScene::MainMenuScene()
    : _menu(std::make_shared<Engine::ui::Menu>(400, 350)),
      _title(std::make_shared<Engine::ui::Label>()),
      _rect(std::make_shared<Engine::ui::Rectangle>()){

        _title->font_size(165);
        _title->init("Pong Game", 0xff4c4c, 400, 60);
        add_entity(_title);

        auto hdl_stub = [](SDL_KeyboardEvent &ev) {if (ev.timestamp){}};
        _menu->font_size(48);
        _menu->setItemPadding(40);
        _menu->add_button("Play", hdl_stub, hdl_stub);
        _menu->add_button("Score", hdl_stub, hdl_stub);
        _menu->add_button("Credits", hdl_stub, hdl_stub);
        _menu->add_button("Exit", hdl_stub, hdl_stub);

        add_entity(_menu);

        _rect->init(20, 300, 20, 120, 0xff4c4c);
        add_entity(_rect);

    }

    void MainMenuScene::sceneEvent(SDL_Event &ev) {

        for_each_entity([&ev, this](Engine::entity::engine_entity_ptr entity){

            if (entity->type() != Engine::IEngineObject::Pressable) return;
            if(ev.type == SDL_KEYDOWN) {
                switch (ev.key.keysym.sym ){
                    case SDLK_DOWN:
                        _menu->nextIndex();
                        break;

                    case SDLK_UP:
                        _menu->prevIndex();
                        break;

                    case SDLK_RETURN:
                        std::cout << "ENTER PRESSED" << std::endl;
                        break;

                    default:
                        break;
                }
            }
        });
    }

    void MainMenuScene::render(Engine::Renderer::engine_renderer &renderer) {
        for_each_entity([&renderer](Engine::entity::engine_entity_ptr entity) {
            entity->render(renderer);
        });
    }

    void MainMenuScene::update() {

    }

}