//#include "SDL.h"
#include "engine/core/Engine.h"
#include "engine/core/EngineBuilder.h"

int main()
{
    Engine::Engine engine;
    Engine::Builder::EngineBuilder engineBuilder;
    engineBuilder.setWindow("Pong Game", 640, 480);

    if (!engineBuilder.build()) return 1;
    engine.run();
    return 0;
}

