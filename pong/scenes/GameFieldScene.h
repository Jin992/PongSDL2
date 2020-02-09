//
// Created by jin on 04.02.20.
//

#ifndef PONGSDL2_GAMEFIELDSCENE_H
#define PONGSDL2_GAMEFIELDSCENE_H

#include <engine/include/Scene.h>
#include "../static/FieldSeparator.h"
#include "../UI/wall.h"
#include "../UI/Paddle.h"
#include "../UI/Ball.h"
#include <engine/include/EngineData.h>
#include <engine/include/Entity.h>
#include <engine/include/Label.h>
#include <list>
#include <random>
#include "../UI/ScoreManager.h"

namespace PongGame {
class GameFieldScene: public Engine::Scene::Scene {
public:
    GameFieldScene();
    void render(Engine::Renderer::engine_renderer &) override;
    void sceneEvent(SDL_Event &ev, double) override;
    void update(double) override ;

private:
    void _ai(std::shared_ptr<Ball>, std::shared_ptr<Paddle>, double);
    std::shared_ptr<Engine::entity::Entity> _calculateCollision(std::shared_ptr<Engine::entity::Entity> tracked_obj);

private:
    int32_t                                                 _win_witdh;
    int32_t                                                 _win_height;
    std::shared_ptr<FieldSeparator>                         _separator;
    std::shared_ptr<PongGame::Wall>                         _wall1;
    std::shared_ptr<PongGame::Wall>                         _wall2;
    std::shared_ptr<PongGame::Paddle>                       _player_paddle;
    std::shared_ptr<PongGame::Paddle>                       _ai_paddle;
    std::shared_ptr<PongGame::Ball>                         _ball;
    std::vector<std::shared_ptr<Engine::entity::Entity>>    _obstacles;
    std::shared_ptr<PongGame::ScoreManager>                 _score_manager;
    std::shared_ptr<Engine::ui::Label>                      _winner;
    bool                                                    _terminate_game;
    const int _half = 2;
    };

}
#endif //PONGSDL2_GAMEFIELDSCENE_H
