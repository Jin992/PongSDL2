//
// Created by jin on 2/5/20.
//

#ifndef PONGSDL2_CREDITSCENE_H
#define PONGSDL2_CREDITSCENE_H

#include <scene/Scene.h>
#include <ui/Label.h>

namespace PongGame {
    class CreditScene: public Engine::Scene::Scene  {
    public:
        CreditScene();
        void render(Engine::Renderer::engine_renderer &) override;
        void sceneEvent(SDL_Event &ev) override;
        void update() override ;

    private:
        std::shared_ptr<Engine::ui::Label>      _title;
        std::shared_ptr<Engine::ui::Label>      _info;
    };
}


#endif //PONGSDL2_CREDITSCENE_H
