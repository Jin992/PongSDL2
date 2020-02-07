//
// Created by jin on 04.02.20.
//

#include <iostream>
#include <zconf.h>
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

                    case SDLK_ESCAPE:
                        Engine::EngineData::EngineData::instance().sceneManager().load_scene("MainMenu");
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
        if (_terminate_game) {
            _score_manager->all_scores_to_zero();
            _terminate_game = false;
            Engine::EngineData::EngineData::instance().sceneManager().load_scene("MainMenu");
        }
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
        int32_t winner = _score_manager->winner();
        if (winner != 0) {
            if (winner == -1) {
                _winner = std::make_shared<Engine::ui::Label>();
                _winner->init("AI           WINS", 0xffffffff, _win_witdh/2 + 10, _win_height/2 - 20);
                _winner->type(Engine::entity::Static);
                add_entity(_winner);
                _terminate_game = true;
            }
            if (winner == 1) {
                _winner = std::make_shared<Engine::ui::Label>();
                _winner->init("PLAYER        WINS", 0xffffffff, _win_witdh/2 + 10, _win_height/2 - 20);
                _winner->type(Engine::entity::Static);
                add_entity(_winner);
                _terminate_game = true;
            }
        }

        prev_obstacle = obstacle;
        _ball->accelerate();
    }

    GameFieldScene::GameFieldScene()
    /// Architecture error can't inherit from Scene window height width, need to fix
    : _win_witdh(Engine::EngineData::EngineData::instance().window().width()),
      _win_height(Engine::EngineData::EngineData::instance().window().height()),
      _separator(std::make_shared<FieldSeparator>()),
      _walls(std::make_shared<PongGame::Wall>(0, 0,  _win_witdh, 10, 0Xfffffff)),
      _walls2(std::make_shared<PongGame::Wall>(0, _win_height-10, _win_witdh , 10, 0Xfffffff)),
      _player_paddle(std::make_shared<PongGame::Paddle>(20, _win_height / 2 - 60, 20, 120,0Xfffffff)),
      _ai_paddle(std::make_shared<PongGame::Paddle>(_win_witdh - 40, _win_height /2 - 60, 20, 120,0Xfffffff)),
      _ball(std::make_shared<PongGame::Ball>(_win_witdh /2, _win_height/2 - 12, 25, 25, 0xffffffff)),
      _score_manager(std::make_shared<ScoreManager>()),
     _terminate_game(0)
    {
        _separator->setColor(0xffffffff);
        _separator->init(Engine::EngineData::EngineData::instance().window().width() / 2, 0, 6, 24, 20);
        /// Add entities to scene
        add_entity(_separator);
        add_entity(_walls);
        add_entity(_walls2);
        add_entity(_player_paddle);
        add_entity(_ai_paddle);
        add_entity(_ball);
        add_entity(_score_manager);
        /// Set which of scene entities would be collidable
        _obstacles.push_back(_player_paddle);
        _obstacles.push_back(_ai_paddle);
        _obstacles.push_back(_walls);
        _obstacles.push_back(_walls2);
    }

    /// Very simple ai logic
    void  GameFieldScene::_ai(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle) {
        std::mt19937 gen(time(0));
        std::uniform_int_distribution<int> distribution(1,200);
        constexpr  int32_t  paddle_speed = 1;

        if (ball->y() > paddle->y() + paddle->h() / 2 && distribution(gen) % 2 == 0 && paddle->x() - ball->x() < 120) {  // If the ball is below the center of the paddle
            paddle->set_y(paddle->y() + paddle_speed);                      // Move downwards
        } else if (ball->y() > paddle->y() + paddle->h() / 2 && distribution(gen) % 3 == 0 && paddle->x() - ball->x() < 200) {  // If the ball is below the center of the paddle
            paddle->set_y(paddle->y() + paddle_speed);                      // Move downwards
        } else if (ball->y() > paddle->y() + paddle->h() / 2 && distribution(gen) % 7 == 0 && paddle->x() - ball->x() < 300) {  // If the ball is below the center of the paddle
            paddle->set_y(paddle->y() + paddle_speed);                      // Move downwards
        }
        else if (ball->y() < paddle->y() + paddle->h() / 2 && distribution(gen) % 2== 0 && paddle->x() - ball->x() < 120) {  // If the ball is above the center of the paddle
            paddle->set_y(paddle->y() - paddle_speed);                          // Move upwards
        } else if (ball->y() < paddle->y() + paddle->h() / 2 && distribution(gen) % 3 == 0 && paddle->x() - ball->x() < 200) {  // If the ball is above the center of the paddle
            paddle->set_y(paddle->y() - paddle_speed);                          // Move upwards
        } else if (ball->y() < paddle->y() + paddle->h() / 2 && distribution(gen) % 7 == 0 && paddle->x() - ball->x() < 300) {  // If the ball is below the center of the paddle
            paddle->set_y(paddle->y() - paddle_speed);                      // Move downwards
        }
    }
    /// Collision manager. calculate collisions
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