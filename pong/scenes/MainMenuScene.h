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
        void onClickDown(SDL_KeyboardEvent &event) override {if (event.timestamp) {}}
        void onClickUp(SDL_KeyboardEvent &event) override {if (event.timestamp) {}}
        void onKeyPressDown(SDL_KeyboardEvent &event) override {if (event.timestamp) {}}
        void onKeyPressUp(SDL_KeyboardEvent &event) override {if (event.timestamp) {}}

        ~MainMenuScene() = default;

    };
}
#endif //PONGSDL2_MAINMENUSCENE_H
