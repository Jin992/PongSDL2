//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_SDLDESTROYER_H
#define PONGSDL2_SDLDESTROYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace Engine {
    struct SDLDestroyer {
        void operator()(SDL_Window *ptr) const {
            SDL_DestroyWindow(ptr);
            SDL_Quit();
        }

        void operator()(SDL_Renderer *ptr) const {
            SDL_DestroyRenderer(ptr);
        }

        void operator()(_TTF_Font *ptr) const {
            TTF_CloseFont(ptr);
            //TTF_Quit();
        }

        void operator() (SDL_Surface *ptr) const {
            SDL_FreeSurface(ptr);
        }

        void operator()(SDL_Texture *ptr) const {
            SDL_DestroyTexture(ptr);
        }
    };
}

#endif //PONGSDL2_SDLDESTROYER_H
