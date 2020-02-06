//
// Created by jin on 04.02.20.
//

#include <iostream>
#include "GameFieldScene.h"

namespace PongGame {
    void GameFieldScene::sceneEvent(SDL_Event &ev) {
        for_each_entity([&ev, this](Engine::entity::engine_entity_ptr entity) {
            if (entity->type() != Engine::entity::Pressable) {}
            if(ev.type == SDL_KEYDOWN) {
                switch (ev.key.keysym.sym ){
                    case SDLK_DOWN:
                        _player_paddle->moveDown();
                        break;

                    case SDLK_UP:
                        _player_paddle->moveUp();
                        break;

                    default:
                        break;
                }
            }
        });
    }

    void GameFieldScene::render(Engine::Renderer::engine_renderer &renderer) {
        for_each_entity([&renderer](Engine::entity::engine_entity_ptr entity) {
            entity->render(renderer);
        });
    }

    void GameFieldScene::update() {
        static std::shared_ptr<Engine::entity::Entity> prev_obstacle;
        // launch ai
        _ai(_ball, _ai_paddle);
        // calculate ball collisions
        auto obstacle = _calculateCollision(_ball);
        if (obstacle != nullptr) {
            if (obstacle != prev_obstacle) {
                if (obstacle->type() == Engine::entity::Collidable) _ball->changeXdirection();
                if (obstacle->type() == Engine::entity::Static) _ball->changeYdirection();
            }
        }
        if (_ball->x() < 0 ) {
            _score_manager->increase_ai_score();
            _ball->respawn();
        }
        if (_ball->x() > (int32_t)Engine::EngineData::EngineData::instance().window().width()) {
            _score_manager->increase_player_score();
            _ball->respawn();
        }

        prev_obstacle = obstacle;
        _ball->accelerate();
    }

    GameFieldScene::GameFieldScene()
    : _separator(std::make_shared<FieldSeparator>()),
    _score_manager(std::make_shared<ScoreManager>())
    {
        /// Architecture error can't inherit from Scene, need to fix
        int32_t half_screen = Engine::EngineData::EngineData::instance().window().width() / 2;
        _separator->setColor(0xffffffff);
        _separator->init(half_screen, 0, 6, 24, 20);
        add_entity(_separator);

        _walls = std::make_shared<PongGame::Wall>(0, 0, Engine::EngineData::EngineData::instance().window().width() , 10, 0Xfffffff);
        add_entity(_walls);

        _walls2 = std::make_shared<PongGame::Wall>(0, Engine::EngineData::EngineData::instance().window().height()-10, Engine::EngineData::EngineData::instance().window().width() , 10, 0Xfffffff);
        add_entity(_walls2);

        _player_paddle = std::make_shared<PongGame::Paddle>(20, Engine::EngineData::EngineData::instance().window().height()/2 - 60, 20, 120,0Xfffffff);
        _ai_paddle = std::make_shared<PongGame::Paddle>(Engine::EngineData::EngineData::instance().window().width() - 40, Engine::EngineData::EngineData::instance().window().height()/2 - 60, 20, 120,0Xfffffff);
        add_entity(_player_paddle);
        add_entity(_ai_paddle);

        _ball = std::make_shared<PongGame::Ball>(Engine::EngineData::EngineData::instance().window().width() /2,
                                                 Engine::EngineData::EngineData::instance().window().height() /2 - 12, 25, 25, 0xffffffff);

        add_entity(_ball);
        add_entity(_score_manager);

        _obstacles.push_back(_player_paddle);
        _obstacles.push_back(_ai_paddle);
        _obstacles.push_back(_walls);
        _obstacles.push_back(_walls2);
    }

    void  GameFieldScene::_ai(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) {
        std::mt19937 gen(time(0));
        std::uniform_int_distribution<int> distribution(1,200);

        if (ball->y() > paddle->y() + paddle->h() / 2 && distribution(gen) % 2 == 0 && paddle->x() - ball->x() < 120) {  // If the ball is below the center of the paddle
            paddle->set_y(paddle->y() + 1);                      // Move downwards
        } else if (ball->y() > paddle->y() + paddle->h() / 2 && distribution(gen) % 3 == 0 && paddle->x() - ball->x() < 200) {  // If the ball is below the center of the paddle
            paddle->set_y(paddle->y() + 1);                      // Move downwards
        } else if (ball->y() > paddle->y() + paddle->h() / 2 && distribution(gen) % 7 == 0 && paddle->x() - ball->x() < 300) {  // If the ball is below the center of the paddle
            paddle->set_y(paddle->y() + 1);                      // Move downwards
        }
        else if (ball->y() < paddle->y() + paddle->h() / 2 && distribution(gen) % 2== 0 && paddle->x() - ball->x() < 120) {  // If the ball is above the center of the paddle
            paddle->set_y(paddle->y() - 1);                          // Move upwards
        } else if (ball->y() < paddle->y() + paddle->h() / 2 && distribution(gen) % 3 == 0 && paddle->x() - ball->x() < 200) {  // If the ball is above the center of the paddle
            paddle->set_y(paddle->y() - 1);                          // Move upwards
        } else if (ball->y() < paddle->y() + paddle->h() / 2 && distribution(gen) % 7 == 0 && paddle->x() - ball->x() < 300) {  // If the ball is below the center of the paddle
            paddle->set_y(paddle->y() - 1);                      // Move downwards
        }
    }

    std::shared_ptr<Engine::entity::Entity>  GameFieldScene::_calculateCollision(std::shared_ptr<Engine::entity::Entity> tracked_obj) {
        int32_t x = 0;
        int32_t y = 0;

        for (auto it : _obstacles) {
            // calculate x axis target center and edge
            int32_t t_x_edge = tracked_obj->w() / _half;
            int32_t o_x_edge = it->w() / _half;
            // calculate x axis obstacle center and edge
            int32_t t_x_center = tracked_obj->x() + t_x_edge;
            int32_t o_x_center = it->x() + o_x_edge;

            // calculate y axis target center and edge
            int32_t t_y_edge = tracked_obj->h() / _half;
            int32_t o_y_edge = it->h() / _half;
            // calculate y axis obstacle center and edge
            int32_t t_y_center = tracked_obj->y() + t_y_edge;
            int32_t o_y_center = it->y() + o_y_edge;

            x = std::abs(t_x_center - o_x_center) < t_x_edge + o_x_edge;
            y = std::abs(t_y_center - o_y_center) < t_y_edge + o_y_edge;
            if (x && y) return it;
        }
        return nullptr;
    }
}