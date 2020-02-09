//
// Created by jin on 2/1/20.
//


#include <TTFFont.h>
#include <EngineData.h>

namespace Engine {
    namespace Font {

        void TTFFont::set_font(const std::string &font_name, uint16_t size) {
            _font_name = font_name;
            _font_size = size;
        }

        void TTFFont::build() {
            _font = engine_font(TTF_OpenFont(_font_name.c_str(), _font_size));
            if (_font == nullptr)
                throw std::string("SDL failed to load ttf font: " + std::string(TTF_GetError()));
        }

        void TTFFont::font_size(uint16_t size) {
            _font_size = size;
            _font.release();
            build();
        }

        uint16_t  TTFFont::font_size() const{
            return _font_size;
        }

        engine_font &TTFFont::get() {
            return _font;
        }

        engine_texture TTFFont::createText(std::string const &text, uint32_t color) {
            // Translate uint to rbga
            uint8_t rbga[4];
            memcpy(rbga, &color, 4);
            SDL_Color _color{rbga[0],rbga[1],rbga[2],rbga[3]};

            // Create surface with text
            engine_sufrace sufrace(TTF_RenderText_Blended(_font.get(), text.c_str(), _color));
            if (sufrace == nullptr)
                throw std::string("Failed to create surface with a text " + std::string(TTF_GetError()));
            // Create texture from the surface
            EngineData::EngineData &data = EngineData::EngineData::instance();
            engine_texture texture(SDL_CreateTextureFromSurface(data.renderer().get().get(), sufrace.get()));
            if (texture == nullptr) {
                sufrace.release();
                throw std::string("Failed to create texture from text surface: " + std::string(SDL_GetError()));
            }
            return texture;
        }

        TTFFont::operator bool() const {
            return !(_font == nullptr);
        }
    }
}