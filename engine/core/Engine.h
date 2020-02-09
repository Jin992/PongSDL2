//
// Created by root on 1/30/20.
//

#ifndef PONGSDL2_ENGINE_H
#define PONGSDL2_ENGINE_H


#include <SDL_rect.h>

namespace Engine {

    class Engine {
    public:
        Engine() = default;
        Engine(Engine const &) = delete;
        Engine(Engine const &&) = delete;
        Engine &operator=(Engine const &) = delete;
        Engine &operator=(Engine const &&) = delete;
        ~Engine() = default;

        /// start game loop
        void run();
    };
}

#endif //PONGSDL2_ENGINE_H
