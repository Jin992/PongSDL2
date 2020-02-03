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

/*        SDL_Rect player_RECT;
        player_RECT.x =10;
        player_RECT.y = 10;
        player_RECT.w = 15;
        player_RECT.h = 90;

        SDL_Rect ball;
        ball.x = 50;
        ball.y = 70;
        ball.w = 15;
        ball.h = 15;*/

        /*SDL_Rect background_RECT;
        background_RECT.x = 0;
        background_RECT.y = 0;
        background_RECT.w = 640;
        background_RECT.y = 480;*/

        //const int player_WIGHT = 333;   //Ширина исходнго изображения
        //const int player_HEIGH = 227;   //Высота исходного изображения
        //double TESTtexture_SCALE = 1.0; //Множетель для зумирования
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

                    case SDL_MOUSEBUTTONDOWN:
                        break;

                    case SDL_MOUSEBUTTONUP:
                        break;

                    case  SDL_KEYDOWN:
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