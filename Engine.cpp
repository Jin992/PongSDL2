//
// Created by root on 1/30/20.
//

#include "Engine.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace PingPong {

    namespace {
        void destroy_window(SDL_Window *ptr) {
            SDL_DestroyWindow(ptr);
            SDL_Quit();
        }

        void destroy_renderer(SDL_Renderer *ptr) {
            SDL_DestroyRenderer(ptr);
        }

        void destroy_ttf_font(_TTF_Font *ptr) {
            TTF_CloseFont(ptr);
            TTF_Quit();
        }
    }

    Engine::Engine(std::string const &title, uint32_t width, uint32_t height)
    : _title(title), _width(width), _height(height)
    {}

    bool Engine::init() {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
            std::cerr << "Failed to init SDL " << SDL_GetError() << std::endl;
            return false;
        }

        if (TTF_Init() < 0) {
            std::cerr << "Failed to initialize TTF " << SDL_GetError() << std::endl;
            return false;
        }

        _window = sdl_window_ptr_t(SDL_CreateWindow(_title.c_str(),
                                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height,SDL_WINDOW_SHOWN), destroy_window);
        if (_window == nullptr) {
            std::cerr << "SDL couldn't be create window: " << SDL_GetError() << std::endl;
            return false;
        }

        _renderer = sdl_renderer_ptr_t(SDL_CreateRenderer(_window.get(),
                                                          -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), destroy_renderer);
        if (_renderer == nullptr) {
            std::cerr << "Renderer couldn't be created: " << SDL_GetError() << std::endl;
            return false;
        }
        /// TODO set propper path to fonts
        _font = sdl_ttf_font_ptr_t(TTF_OpenFont("../fonts/DejaVuSansMono-Bold.ttf", 28), destroy_ttf_font);
        if (_font == nullptr) {
            std::cerr << "Failed to load a font for the application: " << TTF_GetError() << std::endl;
            return false;
        }
        return true;
    }


    void Engine::run() {
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
            SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(_renderer.get());
            SDL_RenderPresent(_renderer.get());
        }
    }
}