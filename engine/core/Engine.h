//
// Created by root on 1/30/20.
//

#ifndef PONGSDL2_ENGINE_H
#define PONGSDL2_ENGINE_H



namespace Engine {

    class Engine {
    public:
        Engine();
        Engine(Engine const &) = delete;
        Engine(Engine const &&) = delete;
        Engine &operator=(Engine const &) = delete;
        Engine &operator=(Engine const &&) = delete;
        ~Engine() = default;

        /// Engine initialize function
        bool init();
        /// start game loop
        void run();

    private:


    };
}

#endif //PONGSDL2_ENGINE_H
