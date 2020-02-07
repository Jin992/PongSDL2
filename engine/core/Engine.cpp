//
// Created by root on 1/30/20.
//

#include "Engine.h"
#include "EngineData.h"
#include <SDL2/SDL.h>
#include <error/EngineError.h>
#include <chrono>

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

        constexpr uint64_t TICK = 4;     // fixed interval between "thinks"
        constexpr uint64_t FRAME = 16;      // minimum time between renders

        uint64_t time = 0;
        std::chrono::steady_clock::time_point last = std::chrono::steady_clock::now();
        std::chrono::steady_clock::time_point frame = std::chrono::steady_clock::now();

        // Start main game loop
        while (data.engine_status()) {

            std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
            time += std::chrono::duration_cast<std::chrono::milliseconds>(now - last).count();
            last = now;

            // check if its time to listen input
            // Check for input events
            while (time >= TICK) {
                while (SDL_PollEvent(&event) != 0) {
                    switch (event.type) {
                        case SDL_QUIT:
                            data.engine_status(false);
                            break;
                            // Process key press event
                        case SDL_KEYDOWN:
                            data.sceneManager().current_scene()->sceneEvent(event);
                            break;

                        default:
                            break;
                    }
                }

                // Execute logic
                data.sceneManager().current_scene()->update();
                time -= TICK;
            }
            // render scene
            // Clear window
            if (now >= frame) {
                SDL_SetRenderDrawColor(data.renderer().get().get(), 0x0, 0x0, 0x0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(data.renderer().get().get());
                data.sceneManager().current_scene()->render(data.renderer().get());
                SDL_RenderPresent(data.renderer().get().get());
                frame = now + std::chrono::milliseconds(FRAME);
            }
        }
    }
}