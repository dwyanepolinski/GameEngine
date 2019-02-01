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
    STOP_MOVE_DOWN,
    START_MOVE_RIGHT_ANIM,
    STOP_MOVE_RIGHT_ANIM,
    START_MOVE_LEFT_ANIM,
    STOP_MOVE_LEFT_ANIM,
    START_MOVE_UP_ANIM,
    STOP_MOVE_UP_ANIM,
    START_MOVE_DOWN_ANIM,
    STOP_MOVE_DOWN_ANIM
};

const double FrameTime = 16;//trzeba przekminić jak kontrolować tempo działania aplikacji (zmienna nie uzywana)

struct event_obj
{
    Event event_t;
    unsigned int entity_id;
    int status;
    bool alive;
};


struct anim_params {
    double period = 5;//wartości (w milisekundach) ustawiamy na ręcznie bo nie mamy mechanizmu wczytywania ich z pliku
    unsigned int ttl = 20;//odpowiada liczbie tekstur w ramach animacji
    double timer = 5;
};

struct move_params {
    double period = 2;
    double timer = 2;
};

#endif
