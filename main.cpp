//#include "SDL.h"
#include <engine/include/Engine.h>
#include <engine/include/EngineBuilder.h>
#include "pong/scenes/MainMenuScene.h"
#include "pong/scenes/CreditScene.h"
#include "pong/scenes/GameFieldScene.h"


int main()
{
    Engine::Engine                  engine;
    Engine::Builder::EngineBuilder  engineBuilder;

    engineBuilder.setWindow("Pong Game", 800, 600);

    engineBuilder.build() ;

    engineBuilder.addScene("MainMenu", std::make_shared<PongGame::MainMenuScene>());
    engineBuilder.addScene("GameField", std::make_shared<PongGame::GameFieldScene>());
    engineBuilder.addScene("Credits", std::make_shared<PongGame::CreditScene>());
    engineBuilder.startup_scene("MainMenu");

    engine.run();
    return 0;
}

