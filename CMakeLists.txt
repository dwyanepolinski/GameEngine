cmake_minimum_required(VERSION 3.7)
project(GameEngine)

set(CMAKE_CXX_STANDARD 11)

set(SDL2_LIBRARY /usr/lib/libSDL2.so)
find_package(SDL2 REQUIRED)

set(SOURCE_FILES main.cpp
    core/Game.cpp
    core/Game.h
    core/ECS/Entity.h
    core/ECS/Component.h
    core/ECS/System.h
    core/ECS/systems/Render.h
#     core/ECS.cpp
#     core/ECS.h
#     core/Scene.cpp
#     core/Scene.h
#     core/components/Render.cpp
#     core/components/Render.h
#     core/File.cpp
#     core/File.h
#     core/components/Control.cpp
#     core/components/Control.h
#     math/Vector2D.cpp
#     math/Vector2D.h
#     core/components/Collider.cpp
#     core/components/Collider.h
#     core/Camera.cpp
#     core/Camera.h
)
add_executable(GameEngine ${SOURCE_FILES})

target_link_libraries(GameEngine ${SDL2_LIBRARY})

#if you are using ubuntu operating system please edit file /usr/lib/x86_64-linux-gnu/cmake/SDL2/sdl2-config.cmake: instead of set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2 "), you should have: set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2")
