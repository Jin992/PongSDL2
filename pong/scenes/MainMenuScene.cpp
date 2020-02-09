//
// Created by jin on 2/1/20.
//

#include <SDL_events.h>
#include <core/EngineData.h>
#include "MainMenuScene.h"
#include <iostream>
#include <config/config.h>

namespace PongGame {
    MainMenuScene::MainMenuScene()
    : _menu(std::make_shared<Engine::ui::Menu>(c_menu_x, c_menu_y)),
      _title(std::make_shared<Engine::ui::Label>()) {

        _title->font_size(c_menu_title_font_size);
        _title->init("Pong Game", c_menu_title_color, c_menu_title_x, c_menu_title_y);
        add_entity(_title);

        auto hdl_stub = [](SDL_KeyboardEvent &ev) {if (ev.timestamp){}};
        auto play_down = [](SDL_KeyboardEvent &ev) {
            if (ev.keysym.sym == SDLK_RETURN) {
                std::string err;
                Engine::EngineData::EngineData::instance().sceneManager().load_scene("GameField");
            }};
        auto credits_down = [](SDL_KeyboardEvent &ev) {
            if (ev.keysym.sym == SDLK_RETURN) {
                std::string err;
                Engine::EngineData::EngineData::instance().sceneManager().load_scene("Credits");
            }};

        auto exit_down = [](SDL_KeyboardEvent &ev) {
            if (ev.keysym.sym == SDLK_RETURN) {
                std::string err;
                Engine::EngineData::EngineData::instance().engine_status(false);
            }};
        
        _menu->font_size(c_menu_item_font_size);
        _menu->set_active_color(c_menu_item_active_color);
        _menu->set_color(c_menu_item_color);
        _menu->setItemPadding(c_menu_item_padding);
        _menu->add_button("Play", play_down,hdl_stub);
        _menu->add_button("Credits", credits_down,hdl_stub);
        _menu->add_button("Exit", exit_down,hdl_stub);

        add_entity(_menu);
    }

    void MainMenuScene::sceneEvent(SDL_Event &ev, double) {

        for_each_entity([&ev, this](Engine::entity::engine_entity_ptr entity){

            if (entity->type() != Engine::entity::Pressable) return;
            if(ev.type == SDL_KEYDOWN) {
                switch (ev.key.keysym.sym ){
                    case SDLK_DOWN:
                        _menu->nextIndex();
                        break;

                    case SDLK_UP:
                        _menu->prevIndex();
                        break;

                    case SDLK_RETURN:
                        _menu->onKeyPressDown(ev.key);
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

    void MainMenuScene::update(double) {

    }
}