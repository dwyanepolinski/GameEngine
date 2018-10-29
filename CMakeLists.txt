cmake_minimum_required(VERSION 3.7)
project(GameEngine)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_BUILD_TYPE Debug)



#set(SDL2_LIBRARY /usr/lib/libSDL2.so)


set(SOURCE_FILES main.cpp
    math/vect.h
    math/vect.cpp
    core/Game.cpp
    core/Game.h
    core/Settings.h
    core/ECS/Entity.h
 #   core/ECS/Entity.cpp
    core/ECS/Component.h
    core/ECS/System.h
    core/ECS/systems/Render.h
 #   core/ECS/systems/Render.cpp
    core/ECS/systems/File.h
 #   core/ECS/systems/File.cpp
    core/ECS/systems/Control.h
 #   core/ECS/systems/Control.cpp
    core/ECS/systems/Texture.h
 #   core/ECS/systems/Texture.cpp
    core/ECS/systems/Event.h
 #   core/ECS/systems/Event.cpp
    core/ECS/systems/Animation.h
 #   core/ECS/systems/Animation.cpp
)
add_executable(GameEngine ${SOURCE_FILES})
find_package(SDL2 REQUIRED)
#find_package(SDL2 REQUIRED QUIET)

if(DEFINED SDL2_FOUND)
	target_link_libraries(GameEngine ${SDL2_LIBRARIES})
else()
	set(SDL2_LIBRARY /usr/lib/libSDL2.so)
	target_link_libraries(GameEngine ${SDL2_LIBRARY})
endif()

#target_link_libraries(GameEngine ${SDL2_LIBRARIES})

#if you are using ubuntu operating system please edit file /usr/lib/x86_64-linux-gnu/cmake/SDL2/sdl2-config.cmake: instead of set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2 "), you should have: set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2")
