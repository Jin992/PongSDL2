cmake_minimum_required(VERSION 3.5)
project(PongSDL2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wshadow")
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/engine/cmake/sdl2)
find_package(SDL2 REQUIRED)

link_directories(${PROJECT_SOURCE_DIR}/engine/include)
include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${PROJECT_SOURCE_DIR}/pong)

add_subdirectory(engine)
#find_library(ENGINE libengine lib)
add_executable(PongSDL2 main.cpp
                        pong/scenes/MainMenuScene.cpp
                        pong/scenes/GameFieldScene.cpp
                        pong/static/FieldSeparator.cpp
                        pong/UI/Paddle.cpp
                        pong/UI/Ball.cpp
                        pong/UI/wall.cpp
                        pong/UI/ScoreManager.cpp
                        pong/scenes/CreditScene.cpp)

#string trailing whitespaces
target_link_libraries(PongSDL2  SDL2::Main  engine)#${ENGINE}})#SDL2::Image SDL2::Mixer)

# Add SDL2 CMake modules
#list(APPEND CMAKE_MODULE_PATH engine/cmake/sdl2)

#find_package(SDL2 REQUIRED)
#find_package(SDL2_ttf REQUIRED)
#find_package(SDL2_image REQUIRED)
#find_package(SDL2_mixer REQUIRED)

#include_directories(${PROJECT_SOURCE_DIR}/engine)
#include_directories(${PROJECT_SOURCE_DIR}/pong)

#add_executable(PongSDL2 main.cpp
#                        engine/core/Engine.cpp
#                        engine/entity/Entity.cpp
#                        engine/core/EngineData.cpp
#                        engine/core/EngineBuilder.cpp
#                        engine/scene/SceneManager.cpp
#                        pong/scenes/MainMenuScene.cpp
#                        engine/window/Window.cpp
#                        engine/renderer/Renderer.cpp
#                        engine/TTFFont.cpp
#                        engine/ui/UIEntity.cpp
#                        engine/ui/Label.cpp
#                        engine/ui/Button.cpp
#                        engine/ui/Menu.cpp
#                        engine/ui/Rectangle.cpp
#                        pong/scenes/GameFieldScene.cpp
#                        pong/static/FieldSeparator.cpp
#                        pong/UI/Paddle.cpp
#                        pong/UI/Ball.cpp
#                        pong/UI/wall.cpp
#                        pong/UI/ScoreManager.cpp
#                        pong/scenes/CreditScene.cpp)

#string trailing whitespaces
#target_link_libraries(PongSDL2 SDL2::Main SDL2::TTF )#SDL2::Image SDL2::Mixer)