cmake_minimum_required(VERSION 3.7)
project(GameEngine)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_BUILD_TYPE Debug)

set(SDL2_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2-2.0.so.0)
find_package(SDL2 REQUIRED)

set(SOURCE_FILES
    main.cpp
    core/event.h
    core/context.h
    core/ilist.h
    core/game.h
    math/vect.h
    math/vect.cpp
    
    core/ecs/manager.h
    core/ecs/base/entity.h
    core/ecs/base/component.h
    core/ecs/base/system.h

    core/ecs/systems/render.h
)
add_executable(GameEngine ${SOURCE_FILES})

target_link_libraries(GameEngine ${SDL2_LIBRARY})

#if you are using ubuntu operating system please edit file /usr/lib/x86_64-linux-gnu/cmake/SDL2/sdl2-config.cmake: instead of set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2 "), you should have: set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2")
