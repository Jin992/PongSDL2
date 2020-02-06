//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_TTFFONT_H
#define PONGSDL2_TTFFONT_H

#include <memory>
#include <core/SDLDestroyer.h>
#include <error/EngineError.h>

struct _TTF_Font;

namespace Engine {
    namespace Font {

        typedef std::unique_ptr<_TTF_Font, SDLDestroyer>    engine_font;
        typedef std::unique_ptr<SDL_Surface, SDLDestroyer>  engine_sufrace;
        typedef std::unique_ptr<SDL_Texture, SDLDestroyer>  engine_texture;

        class TTFFont {
        public:
            TTFFont() = default;

            TTFFont(TTFFont const&) = delete;
            TTFFont operator=(TTFFont const&) = delete;
            explicit  operator bool() const;
            void set_font(std::string const &, uint16_t);
            void font_size(uint16_t size);
            uint16_t font_size() const;
            void build();
            engine_font &get();

            engine_texture createText(std::string const &, uint32_t);

        private:
            engine_font _font;
            std::string _font_name;
            uint16_t    _font_size;
        };
    }
}



#endif //PONGSDL2_TTFFONT_H
