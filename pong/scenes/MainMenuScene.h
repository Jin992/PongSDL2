//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_MAINMENUSCENE_H
#define PONGSDL2_MAINMENUSCENE_H

#include <SDL_render.h>
#include "engine/include/Scene.h"
#include <engine/include/TTFFont.h>
#include <engine/include/Renderer.h>
#include "engine/include/Menu.h"
#include <engine/include/Rectangle.h>

namespace PongGame {

    class MainMenuScene: public Engine::Scene::Scene {
    public:
        MainMenuScene();
        void render(Engine::Renderer::engine_renderer &) override;
        void sceneEvent(SDL_Event &ev, double) override;
        void update(double) override ;

        ~MainMenuScene() = default;

    private:
        std::shared_ptr<Engine::ui::Menu>       _menu;
        std::shared_ptr<Engine::ui::Label>      _title;

    };
}
#endif //PONGSDL2_MAINMENUSCENE_H
