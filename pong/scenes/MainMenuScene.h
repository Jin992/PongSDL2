//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_MAINMENUSCENE_H
#define PONGSDL2_MAINMENUSCENE_H

#include <SDL_render.h>
#include "scene/Scene.h"
#include <TTFFont.h>
#include <renderer/Renderer.h>
#include "ui/Menu.h"
#include <ui/Rectangle.h>
#include <iostream>


namespace PongGame {

    class downHDL {
        void operator()(SDL_KeyboardEvent &ev){
            if (ev.keysym.sym == SDLK_RETURN) {
                std::string err;
                Engine::EngineData::EngineData::instance().sceneManager().load_scene("GameField", err);
            }
        }
    };


    class MainMenuScene: public Engine::Scene::Scene {
    public:
        MainMenuScene();
        void render(Engine::Renderer::engine_renderer &) override;
        void sceneEvent(SDL_Event &ev) override;
        void update() override ;

        void hdl_stub(SDL_KeyboardEvent &ev) {
            if (ev.timestamp){}};
        void onDown(SDL_KeyboardEvent &ev) {
            if (ev.keysym.sym == SDLK_RETURN) {
                std::string err;
                Engine::EngineData::EngineData::instance().sceneManager().load_scene("GameField",err);
            }};


        ~MainMenuScene() = default;

    private:
        std::shared_ptr<Engine::ui::Menu>       _menu;
        std::shared_ptr<Engine::ui::Label>      _title;
        std::shared_ptr<Engine::ui::Rectangle>  _rect;

    };
}
#endif //PONGSDL2_MAINMENUSCENE_H
