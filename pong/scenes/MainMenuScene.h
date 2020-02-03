//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_MAINMENUSCENE_H
#define PONGSDL2_MAINMENUSCENE_H

#include <SDL_render.h>
#include "scene/Scene.h"
#include "../UI/TextButton.h"
#include <TTFFont.h>
#include <renderer/Renderer.h>

namespace PongGame {
    class MainMenuScene: public Engine::Scene::Scene {
    public:
        MainMenuScene();
        void render(Engine::Renderer::engine_renderer &) override;
        void update() override ;

        ~MainMenuScene() = default;

    };
}
#endif //PONGSDL2_MAINMENUSCENE_H
