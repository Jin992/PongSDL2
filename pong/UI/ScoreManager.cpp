//
// Created by jin on 2/5/20.
//

#include "ScoreManager.h"

namespace PongGame {
    ScoreManager::ScoreManager()
            :_score_player_label(std::make_shared<Engine::ui::Label>()),
             _score_ai_label(std::make_shared<Engine::ui::Label>()),
             _score_ai(0), _score_player(0)
    {
        int32_t half_screen = Engine::EngineData::EngineData::instance().window().width() / 2;
        type(Engine::entity::Static);
        _score_player_label->init("0", 0xffffffff, half_screen/2, 20);
        _score_player_label->type(Engine::entity::Static);
        _score_ai_label->init("0", 0xffffffff, half_screen + half_screen/2, 20);
        _score_ai_label->type(Engine::entity::Static);

    }

    void ScoreManager::increase_player_score() {
        _score_player++;
        _score_player_label->set_text(std::to_string(_score_player));
    }

    void ScoreManager::increase_ai_score() {
        _score_ai++;
        _score_ai_label->set_text(std::to_string(_score_ai));
    }

    void ScoreManager::render(Engine::Renderer::engine_renderer &renderer){
        _score_player_label->render(renderer);
        _score_ai_label->render(renderer);
    }

    void ScoreManager::update() {}


    int32_t ScoreManager::winner() {
        if (_score_player >= 10) return 1;
        if (_score_ai >= 10) return -1;
        return 0;
    }

}