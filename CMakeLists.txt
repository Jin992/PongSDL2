cmake_minimum_required(VERSION 3.15)
project(PongSDL2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wshadow")
# Add SDL2 CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(PongSDL2 main.cpp
                        engine/core/Engine.cpp
                        engine/scene/Scene.cpp
        engine/Point.cpp
                        engine/entity/Entity.cpp
                        engine/core/EngineData.cpp
                        engine/core/EngineBuilder.cpp
                        engine/scene/SceneManager.cpp MainMenuScene.cpp MainMenuScene.h)

#string trailing whitespaces
target_link_libraries(PongSDL2 SDL2::Main SDL2::TTF)