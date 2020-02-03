//
// Created by jin on 2/1/20.
//

#include <SDL_events.h>
#include <core/EngineData.h>
#include "MainMenuScene.h"
#include <iostream>

namespace PongGame {
    MainMenuScene::MainMenuScene() {
        //_play_button.init("PLAY", -1, 280, 160, err);
        add_entity(std::make_shared<ui::TextButton>("Play", -1, 320, 180));
        add_entity(std::make_shared<ui::TextButton>("Score", -1, 320, 205));
        add_entity(std::make_shared<ui::TextButton>("Credits", -1, 320, 230));
        add_entity(std::make_shared<ui::TextButton>("Exit", -1, 320, 255));

    }

    void MainMenuScene::render(Engine::Renderer::engine_renderer &renderer) {
        for_each_entity([&renderer](Engine::entity::engine_entity_ptr entity) {
            entity->render(renderer);
        });
    }

    void MainMenuScene::update() {

    }

   /* void MainMenuScene::key_up(SDL_KeyboardEvent &event) {
        if(event.timestamp) {}
    }

    void MainMenuScene::key_down(SDL_KeyboardEvent &event) {
        if (event.timestamp) {}
    }*/


}