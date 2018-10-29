#ifndef GAMEENGINE_SYSTEM_H
#define GAMEENGINE_SYSTEM_H

#include <string>
#include <vector>
#include "../../math/vect.h"
#include <SDL2/SDL.h>
#include "Component.h"
#include <queue>

enum Event
{
    IDLE,
    START_MOVE_RIGHT,
    STOP_MOVE_RIGHT,
    START_MOVE_LEFT,
    STOP_MOVE_LEFT,
    START_MOVE_UP,
    STOP_MOVE_UP,
    START_MOVE_DOWN,
    STOP_MOVE_DOWN
};

struct event_obj
{
    Event event_t;
    unsigned int entity_id;
    int status;
};

#endif
