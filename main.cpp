//#include "SDL.h"
#include <core/Engine.h>
#include <core/EngineBuilder.h>
#include <error/EngineError.h>
#include <iostream>
#include "pong/scenes/MainMenuScene.h"
#include "pong/scenes/GameFieldScene.h"

int main()
{
    Engine::Engine                  engine;
    Engine::Builder::EngineBuilder  engineBuilder;

    engineBuilder.setWindow("Pong Game", 800, 600);
    engineBuilder.setFont("../fonts/ARCADECLASSIC.ttf", 32);

    engineBuilder.build() ;

    engineBuilder.addScene("MainMenu", std::make_shared<PongGame::MainMenuScene>());
    engineBuilder.addScene("GameField", std::make_shared<PongGame::GameFieldScene>());
    engineBuilder.startup_scene("MainMenu");

    engine.run();
    return 0;
}

