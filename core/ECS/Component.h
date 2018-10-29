#ifndef GAMEENGINE_COMPONENT_H
#define GAMEENGINE_COMPONENT_H

#include "../Settings.h"
#include "System.h"

enum Component
{
    COMPONENT_NONE = 0,
    COMPONENT_POSITION = 1 << 0,
    COMPONENT_DISPLACEMENT = 1 << 1,
    COMPONENT_SIZE = 1 << 2,
    COMPONENT_TEXTURE = 1 << 3,
    COMPONENT_TXMAP = 1 << 4,
    COMPONENT_ANIMATION = 1 << 5
};

struct Position
{
    vect pos;
};

struct Displacement
{
    vect vel;
    double v;
};

struct Size
{
    int w;
    int h;
};

struct Texture
{
    SDL_Texture *texture;
    SDL_Rect source_rect;
    SDL_Rect destignation_rect;
    int layer;
    int texture_id;
};

struct Map
{
    int t[MAX_MAP_SIZE][MAX_MAP_SIZE] = {{0}};
    SDL_Rect src_rect[MAX_MAP_SIZE][MAX_MAP_SIZE];
    SDL_Rect dst_rect[MAX_MAP_SIZE][MAX_MAP_SIZE];
};

struct Collision
{
    int collides;
};

struct Animation_Texture
{
    SDL_Texture *texture;
    SDL_Rect source_rect;
    SDL_Rect destignation_rect;
    int layer;
    int texture_id;
};

struct Animation
{
    std::vector<std::vector<unsigned int>> animations;
};

#endif
