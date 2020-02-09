cmake_minimum_required(VERSION 3.5)
project(engine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wshadow")
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(engine
        src/Button.cpp
        src/Engine.cpp
        src/EngineBuilder.cpp
        src/EngineData.cpp
        src/Entity.cpp
        src/Label.cpp
        src/Menu.cpp
        src/Rectangle.cpp
        src/Renderer.cpp
        src/SceneManager.cpp
        src/TTFFont.cpp
        src/UIEntity.cpp
        src/Window.cpp)

target_link_libraries(engine SDL2::Main SDL2::TTF)