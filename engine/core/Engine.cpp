//
// Created by root on 1/30/20.
//

#include "Engine.h"
#include "EngineData.h"
#include <SDL2/SDL.h>
#include <error/EngineError.h>

namespace Engine {
    void Engine::run() {
        // Error handler
        Error::EngineError err;
        // Engine data singleton reference
        EngineData::EngineData &data = EngineData::EngineData::instance();
        // Check if engine  data has been initialized by builder
        if (data.state() == EngineData::BuildState::Uninitialized) return;
        SDL_Event   event;

        // Turn on engine
        data.engine_status(true);

        // Start main game loop
        while (data.engine_status()) {
            // Check for input events
            while(SDL_PollEvent(&event) != 0) {
                switch(event.type) {
                    case SDL_QUIT:
                        data.engine_status(false);
                        break;
                    // Process key press event
                    case  SDL_KEYDOWN:
                        data.sceneManager().current_scene()->sceneEvent(event);
                        break;

                    default:
                        break;
                }
            }
            // Clear window
            SDL_SetRenderDrawColor(data.renderer().get().get(), 0x0, 0x0, 0x0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(data.renderer().get().get());
            // Execute logic
            data.sceneManager().current_scene()->update();
            // render scene
            data.sceneManager().current_scene()->render(data.renderer().get());
            SDL_RenderPresent(data.renderer().get().get());
        }
    }
}