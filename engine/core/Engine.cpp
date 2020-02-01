//
// Created by root on 1/30/20.
//

#include "Engine.h"
#include "EngineData.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace Engine {

    Engine::Engine()
    {}


    void Engine::run() {
        /*while (true) // game loop
        {
            readHumanInterfaceDevices();
            if (quitButtonPressed()) {
                break; // exit the game loop
            }
            movePaddles();
            moveBall();
            collideAndBounceBall();
            if (ballImpactedSide(LEFT_PLAYER)) {
                incremenentScore(RIGHT_PLAYER);
                resetBall();
            } else if (ballImpactedSide(RIGHT_PLAYER)) {
                incrementScore(LEFT_PLAYER);
                resetBall();
            }
            renderPlayfield();
        }*/

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

                    default:
                        break;
                }
            }
            SDL_SetRenderDrawColor(data.renderer().get(), 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(data.renderer().get());
            SDL_RenderPresent(data.renderer().get());
        }
    }
}