//
// Created by root on 1/30/20.
//

#ifndef PONGSDL2_ISCENE_H
#define PONGSDL2_ISCENE_H

#include <memory>

// Forward declarations
struct SDL_KeyboardEvent;
struct SDL_Renderer;

namespace PingPong {
    class IScene;

    typedef std::shared_ptr<IScene> iscene_ptr_t;

    class IScene {
    public:
        virtual void render() = 0;
        virtual void update() = 0;
        virtual void exit() = 0;
        virtual void key_down(SDL_KeyboardEvent &event);
        virtual void key_up(SDL_KeyboardEvent &event);
    };
}


#endif //PONGSDL2_ISCENE_H
