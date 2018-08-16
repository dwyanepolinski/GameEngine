cmake_minimum_required(VERSION 3.7)
project(GameEngine)

set(CMAKE_CXX_STANDARD 11)

set(SDL2_INCLUDE_DIR /usr/include/SDL2)
set(SDL2_LIBRARY /usr/lib/libSDL2.so)

set(SOURCE_FILES main.cpp core/Game.cpp core/Game.h core/ECS.cpp core/ECS.h core/Scene.cpp core/Scene.h core/components/Render.cpp core/components/Render.h core/File.cpp core/File.h core/components/Control.cpp core/components/Control.h math/Vector2D.cpp math/Vector2D.h core/components/Collider.cpp core/components/Collider.h core/Camera.cpp core/Camera.h)
add_executable(GameEngine ${SOURCE_FILES})

target_link_libraries(GameEngine ${SDL2_LIBRARY})