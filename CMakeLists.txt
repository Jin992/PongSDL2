cmake_minimum_required(VERSION 3.5)
project(PongSDL2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wshadow")

link_directories(${PROJECT_SOURCE_DIR}/engine/include)
include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${PROJECT_SOURCE_DIR}/pong)

add_subdirectory(engine)
add_executable(PongSDL2 main.cpp
                        pong/scenes/MainMenuScene.cpp
                        pong/scenes/GameFieldScene.cpp
                        pong/static/FieldSeparator.cpp
                        pong/UI/Paddle.cpp
                        pong/UI/Ball.cpp
                        pong/UI/wall.cpp
                        pong/UI/ScoreManager.cpp
                        pong/scenes/CreditScene.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} engine)