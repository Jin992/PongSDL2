//
// Created by root on 1/30/20.
//

#include "Engine.h"
#include "EngineData.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <error/EngineError.h>

namespace Engine {

    Engine::Engine()
    {}


    void Engine::run() {
        Error::EngineError err;
        EngineData::EngineData &data = EngineData::EngineData::instance();
        if (data.state() == EngineData::BuildState::Uninitialized) return;
        SDL_Event   event;
        bool        stop = false;
        while (!stop) {
            while(SDL_PollEvent(&event) != 0) {
                switch(event.type) {
                    case SDL_QUIT:
                        stop = true;
                        break;

                    case  SDL_KEYDOWN:
                        data.sceneManager().current_scene(err)->sceneEvent(event);
                        break;

                    case SDL_KEYUP:
                        break;


                    default:
                        break;
                }
            }

            SDL_SetRenderDrawColor(data.renderer().get().get(), 0x0, 0x0, 0x0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(data.renderer().get().get());
            data.sceneManager().current_scene(err)->render(data.renderer().get());
            SDL_RenderPresent(data.renderer().get().get());
        }
    }
}