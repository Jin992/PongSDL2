cmake_minimum_required(VERSION 3.15)
project(PongSDL2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wshadow")
# Add SDL2 CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
#find_package(SDL2_image REQUIRED)
#find_package(SDL2_mixer REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/engine)

add_executable(PongSDL2 main.cpp
                        engine/core/Engine.cpp
        engine/entity/Entity.cpp
                        engine/core/EngineData.cpp
                        engine/core/EngineBuilder.cpp
                        engine/scene/SceneManager.cpp pong/scenes/MainMenuScene.cpp pong/scenes/MainMenuScene.h engine/window/Window.cpp engine/window/Window.h engine/renderer/Renderer.cpp engine/renderer/Renderer.h engine/error/EngineError.cpp engine/error/EngineError.h engine/TTFFont.cpp engine/TTFFont.h engine/ui/UIEntity.cpp engine/ui/UIEntity.h engine/ui/Label.cpp engine/ui/Label.h engine/ui/Button.cpp engine/ui/Button.h engine/ui/Menu.cpp engine/ui/Menu.h engine/ui/Rectangle.cpp engine/ui/Rectangle.h pong/scenes/GameFieldScene.cpp pong/scenes/GameFieldScene.h pong/static/FieldSeparator.cpp pong/static/FieldSeparator.h)

#string trailing whitespaces
target_link_libraries(PongSDL2 SDL2::Main SDL2::TTF )#SDL2::Image SDL2::Mixer)