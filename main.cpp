//#include "SDL.h"
#include <core/Engine.h>
#include <core/EngineBuilder.h>
#include <error/EngineError.h>
#include <iostream>
#include "pong/scenes/MainMenuScene.h"

int main()
{
    Engine::Error::EngineError      err;
    Engine::Engine                  engine;
    Engine::Builder::EngineBuilder  engineBuilder;

    engineBuilder.setWindow("Pong Game", 800, 600);
    engineBuilder.setFont("../fonts/ARCADECLASSIC.ttf", 32);

    //PongGame::MainMenuScene mainMenu;
    //Engine::Scene::engine_scene_p main = std::make_shared<Engine::Scene::Scene>(new PongGame::MainMenuScene());
    std::string err1;


    if (!engineBuilder.build(err)) {
        std::cerr << err.err_msg() << std::endl;
        return 1;
    }
    //Engine::Scene::engine_scene_ptr main = ;
    engineBuilder.addScene("MainMenu", std::make_shared<PongGame::MainMenuScene>(), err1);
    engineBuilder.startup_scene("MainMenu", err1);

    engine.run();
    return 0;
}

