//
// Created by jin on 04.02.20.
//

#include <iostream>
#include <zconf.h>
#include "GameFieldScene.h"
#include "../config/config.h"

namespace PongGame {
    void GameFieldScene::sceneEvent(SDL_Event &ev, double) {
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

    void GameFieldScene::update(double elapsed) {
        static std::shared_ptr<Engine::entity::Entity> prev_obstacle;
        // launch ai
        _ai(_ball, _ai_paddle, elapsed);
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
        _ball->accelerate(elapsed);
    }

    GameFieldScene::GameFieldScene()
    /// Architecture error can't inherit from Scene window height width, need to fix
    : _win_witdh(Engine::EngineData::EngineData::instance().window().width()),
      _win_height(Engine::EngineData::EngineData::instance().window().height()),
      _separator(std::make_shared<FieldSeparator>()),
      _wall1(std::make_shared<PongGame::Wall>(0, 0,  _win_witdh, c_wall_h, c_wall_color)),
      _wall2(std::make_shared<PongGame::Wall>(0, _win_height-10, _win_witdh , c_wall_h, c_wall_color)),
      _player_paddle(std::make_shared<PongGame::Paddle>(20, _win_height / 2 - c_paddle_w / 2, c_paddle_w, c_paddle_h, c_paddle_color)),
      _ai_paddle(std::make_shared<PongGame::Paddle>(_win_witdh - 40, _win_height /2 - c_paddle_w / 2,  c_paddle_w, c_paddle_h, c_paddle_color)),
      _ball(std::make_shared<PongGame::Ball>(_win_witdh /2, _win_height/2 - 12, c_ball_w, c_ball_h, c_ball_color)),
      _score_manager(std::make_shared<ScoreManager>()),
     _terminate_game(0)
    {
        _separator->setColor(c_field_sep_color);
        _separator->init(Engine::EngineData::EngineData::instance().window().width() / 2, 0, c_field_sep_w, c_field_sep_h, c_field_sep_padding);
        /// Add entities to scene
        add_entity(_separator);
        add_entity(_wall1);
        add_entity(_wall2);
        add_entity(_player_paddle);
        add_entity(_ai_paddle);
        add_entity(_ball);
        add_entity(_score_manager);
        /// Set which of scene entities would be collidable
        _obstacles.push_back(_player_paddle);
        _obstacles.push_back(_ai_paddle);
        _obstacles.push_back(_wall1);
        _obstacles.push_back(_wall2);
    }

    /// Very simple ai logic
    void  GameFieldScene::_ai(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle, double elapsed) {
        if (ball->xSpeed() < 0) return;
        std::mt19937 gen(time(0));
        std::uniform_int_distribution<int> distribution(1,10);

        if (ball->y() > paddle->y() + paddle->h() / 2 && distribution(gen) % 2 == 0 && paddle->x() - ball->x() < 300)  // If the ball is below the center of the paddle
            paddle->moveDown(elapsed);
        else if (ball->y() > paddle->y() + paddle->h() / 2 && distribution(gen) % 3 == 0 && paddle->x() - ball->x() < 350)  // If the ball is below the center of the paddle
            paddle->moveDown(elapsed);
        else if (ball->y() > paddle->y() + paddle->h() / 2 && distribution(gen) % 7 == 0 && paddle->x() - ball->x() < 400)  // If the ball is below the center of the paddle
            paddle->moveDown(elapsed);
        else if (ball->y() < paddle->y() + paddle->h() / 2 && distribution(gen) % 2== 0 && paddle->x() - ball->x() < 300)  // If the ball is above the center of the paddle
            paddle->moveUp(elapsed);
        else if (ball->y() < paddle->y() + paddle->h() / 2 && distribution(gen) % 3 == 0 && paddle->x() - ball->x() < 350)  // If the ball is above the center of the paddle
            paddle->moveUp(elapsed);
        else if (ball->y() < paddle->y() + paddle->h() / 2 && distribution(gen) % 7 == 0 && paddle->x() - ball->x() < 400)  // If the ball is below the center of the paddle
            paddle->moveUp(elapsed);
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