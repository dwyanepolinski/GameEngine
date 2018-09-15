

#ifndef GAMEENGINE_COMPONENT_H
#define GAMEENGINE_COMPONENT_H

#include <SDL2/SDL_system.h>
#include <string>


enum Component{
    COMPONENT_NONE = 0,
    COMPONENT_POSITION = 1 << 0,
    COMPONENT_DISPLACEMENT = 1 << 1,
    COMPONENT_SIZE = 1 << 2,
    COMPONENT_TEXTURE = 1 << 3
};


struct Position{
    vect pos;
};

struct Displacement{
    vect vel;
    double v;
};

struct Size{
    int w;
    int h;
};

struct Texture{
    SDL_Texture* texture;
    SDL_Rect destignation_rect;
    int layer;
};

    


#endif
