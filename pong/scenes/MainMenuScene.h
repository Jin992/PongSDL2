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


namespace PongGame {
    class MainMenuScene: public Engine::Scene::Scene {
    public:
        MainMenuScene();
        void render(Engine::Renderer::engine_renderer &) override;
        void sceneEvent(SDL_Event &ev) override;
        void update() override ;

        ~MainMenuScene() = default;

    private:
        std::shared_ptr<Engine::ui::Menu>  _menu;
        std::shared_ptr<Engine::ui::Label> _title;

    };
}
#endif //PONGSDL2_MAINMENUSCENE_H
