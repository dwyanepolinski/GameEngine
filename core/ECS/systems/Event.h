#pragma once
#include "../Entity.h"
#include "../System.h"
#include "Animation.h"
#include "Control.h"

namespace EventSystem
{

std::queue<event_obj> events_queue;

void addEvent(event_obj obj)
{
    events_queue.push(obj);
}

event_obj changeEventType(event_obj obj, Event e)
{
    obj.event_t = e;
    return obj;
}

void eventsHandling()
{
    event_obj e;

    while (!events_queue.empty())
    {
        e = events_queue.front();
        if (e.event_t != Event::IDLE)
        {
            if (Entity::mask[e.entity_id] & CONTROL_MASK)
                ControlSystem::eventsHandling(e);

            if (Entity::mask[e.entity_id] & ANIMATION_MASK)
                AnimationSystem::eventsHandling(e);
        }

        events_queue.pop();
    }
}

void event_handler(SDL_Event *event)
{
    if (Entity::master == -1)
        return;

    event_obj e;
    e.entity_id = Entity::master;
    e.event_t = Event::IDLE;
    switch (event->key.keysym.sym)
    {
    case SDLK_w:
        switch (event->type)
        {
        case SDL_KEYDOWN:
            e.event_t = Event::START_MOVE_UP;
            break;
        case SDL_KEYUP:
            e.event_t = Event::STOP_MOVE_UP;
            break;
        }
        break;
    case SDLK_s:
        switch (event->type)
        {
        case SDL_KEYDOWN:
            e.event_t = Event::START_MOVE_DOWN;
            break;
        case SDL_KEYUP:
            e.event_t = Event::STOP_MOVE_DOWN;
            break;
        }
        break;
    case SDLK_d:
        switch (event->type)
        {
        case SDL_KEYDOWN:
            e.event_t = Event::START_MOVE_RIGHT;
            break;
        case SDL_KEYUP:
            e.event_t = Event::STOP_MOVE_RIGHT;
            break;
        }
        break;
    case SDLK_a:
        switch (event->type)
        {
        case SDL_KEYDOWN:
            e.event_t = Event::START_MOVE_LEFT;
            break;
        case SDL_KEYUP:
            e.event_t = Event::STOP_MOVE_LEFT;
        }
        break;
    default:
        break;
    }
    addEvent(e);
}
} // namespace EventSystem