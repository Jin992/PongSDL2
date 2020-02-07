//
// Created by jin on 04.02.20.
//

#ifndef PONGSDL2_GAMEFIELDSCENE_H
#define PONGSDL2_GAMEFIELDSCENE_H

#include <scene/Scene.h>
#include "../static/FieldSeparator.h"
#include "../UI/wall.h"
#include "../UI/Paddle.h"
#include "../UI/Ball.h"
#include <core/EngineData.h>
#include <entity/Entity.h>
#include <ui/Label.h>
#include <list>
#include <random>
#include "../UI/ScoreManager.h"

namespace PongGame {
class GameFieldScene: public Engine::Scene::Scene {
public:
    GameFieldScene();
    void render(Engine::Renderer::engine_renderer &) override;
    void sceneEvent(SDL_Event &ev) override;
    void update() override ;

private:
    void _ai(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle);
    std::shared_ptr<Engine::entity::Entity> _calculateCollision(std::shared_ptr<Engine::entity::Entity> tracked_obj);

private:
    int32_t                                                 _win_witdh;
    int32_t                                                 _win_height;
    std::shared_ptr<FieldSeparator>                         _separator;
    std::shared_ptr<PongGame::Wall>                         _walls;
    std::shared_ptr<PongGame::Wall>                         _walls2;
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
