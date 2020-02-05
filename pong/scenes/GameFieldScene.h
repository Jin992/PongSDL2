//
// Created by jin on 04.02.20.
//

#ifndef PONGSDL2_GAMEFIELDSCENE_H
#define PONGSDL2_GAMEFIELDSCENE_H

#include <scene/Scene.h>
#include "../static/FieldSeparator.h"
#include "../UI/wall.h"
#include <core/EngineData.h>
#include <entity/Entity.h>
#include <ui/Label.h>
#include <list>

namespace PongGame {
class GameFieldScene: public Engine::Scene::Scene {
public:
    GameFieldScene()
    : _separator(std::make_shared<FieldSeparator>()),
      _score_player(std::make_shared<Engine::ui::Label>()),
      _score_ai(std::make_shared<Engine::ui::Label>())
    {
        /// Architecture error can't inherit from Scene, need to fix
        int32_t half_screen = Engine::EngineData::EngineData::instance().window().width() / 2;
        _separator->setColor(0xffffff);
        _separator->init(half_screen, 0, 6, 24, 20);
        add_entity(_separator);

        _score_player->init("0", 0xffffff, half_screen/2, 20);
        _score_player->type(Engine::IEngineObject::Static);
        _score_ai->init("0", 0xffffff, half_screen + half_screen/2, 20);
        _score_ai->type(Engine::IEngineObject::Static);
        add_entity(_score_player);
        add_entity(_score_ai);

        _walls = std::make_shared<PongGame::Wall>(0, 0, Engine::EngineData::EngineData::instance().window().width() , 10, 0Xfffff);
        add_entity(_walls);

        _walls2 = std::make_shared<PongGame::Wall>(0, Engine::EngineData::EngineData::instance().window().height()-10, Engine::EngineData::EngineData::instance().window().width() , 10, 0Xfffff);
        add_entity(_walls2);
    }
    void render(Engine::Renderer::engine_renderer &) override;
    void sceneEvent(SDL_Event &ev) override;
    void update() override ;
private:
    std::shared_ptr<FieldSeparator >_separator;
    std::shared_ptr<Engine::ui::Label> _score_player;
    std::shared_ptr<Engine::ui::Label> _score_ai;
    std::shared_ptr<PongGame::Wall>    _walls;
    std::shared_ptr<PongGame::Wall>    _walls2;
    };

}
#endif //PONGSDL2_GAMEFIELDSCENE_H
