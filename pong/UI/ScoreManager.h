//
// Created by jin on 2/5/20.
//

#ifndef PONGSDL2_SCOREMANAGER_H
#define PONGSDL2_SCOREMANAGER_H

#include <engine/include/Entity.h>
#include <engine/include/Label.h>
#include <iostream>

namespace PongGame {
class ScoreManager: public Engine::entity::Entity {
public:
    ScoreManager();
    void increase_player_score();
    void increase_ai_score();
    void all_scores_to_zero();
    void render(Engine::Renderer::engine_renderer &renderer) override;
    void update(double) override;
    int32_t winner();

private:
    std::shared_ptr<Engine::ui::Label>                      _score_player_label;
    std::shared_ptr<Engine::ui::Label>                      _score_ai_label;
    int32_t                                                 _score_ai;
    int32_t                                                 _score_player;
    };
}


#endif //PONGSDL2_SCOREMANAGER_H
