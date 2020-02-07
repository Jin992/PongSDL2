//
// Created by jin on 2/5/20.
//

#ifndef PONGSDL2_SCOREMANAGER_H
#define PONGSDL2_SCOREMANAGER_H

#include <entity/Entity.h>
#include <ui/Label.h>
#include <iostream>

namespace PongGame {
class ScoreManager: public Engine::entity::Entity {
public:
    ScoreManager();
    void increase_player_score();
    void increase_ai_score();
    void render(Engine::Renderer::engine_renderer &renderer) override;
    void update() override;
    int32_t winner();

private:
    std::shared_ptr<Engine::ui::Label>                      _score_player_label;
    std::shared_ptr<Engine::ui::Label>                      _score_ai_label;
    int32_t                                                 _score_ai;
    int32_t                                                 _score_player;
    };
}


#endif //PONGSDL2_SCOREMANAGER_H
