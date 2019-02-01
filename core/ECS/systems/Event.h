#pragma once
#include "../Entity.h"
#include "../System.h"
#include "Animation.h"
#include "Control.h"
#include<algorithm>

namespace EventSystem
{

std::vector<event_obj> events_vec;

void addEvent(event_obj obj)
{
    bool istnieje = false;
    for(int i=0;i<events_vec.size();++i){
        if (events_vec[i].event_t == obj.event_t){
            istnieje = true;
            break;
        }
    }
    if(!istnieje) events_vec.push_back(obj);
}

event_obj changeEventType(event_obj obj, Event e)
{
    obj.event_t = e;
    return obj;
}

void eventsHandling()
{
    for(auto& item:events_vec){

        if (item.event_t != Event::IDLE)
        {
            if (Entity::mask[item.entity_id] & CONTROL_MASK){
                    ControlSystem::eventsHandling(item);
            }
                
            if (Entity::mask[item.entity_id] & ANIMATION_MASK){
                    AnimationSystem::eventsHandling(item);
            }
                
        }
    }

    events_vec.erase(std::remove_if(events_vec.begin(),events_vec.end(),[&](event_obj e){return !e.alive;}),events_vec.end());
}

event_obj createEvent(unsigned int entity, Event event_type){
	event_obj e;
    e.entity_id = entity;
    e.event_t = event_type;
    e.alive = true;
	return std::move(e);
}

void event_handler(SDL_Event *event)
{
    if (Entity::master == -1)
        return;

    event_obj e;
    e.entity_id = Entity::master;
    e.event_t = Event::IDLE;
    e.alive = true;
    
    switch (event->key.keysym.sym)
    {
    case SDLK_w:
        switch (event->type)
        {
        case SDL_KEYDOWN:
            e.event_t = Event::START_MOVE_UP;
               addEvent(e);
            break;
        case SDL_KEYUP:
            e.event_t = Event::STOP_MOVE_UP;
               addEvent(e);
            break;
        }
        break;
    case SDLK_s:
        switch (event->type)
        {
        case SDL_KEYDOWN:
            e.event_t = Event::START_MOVE_DOWN;
               addEvent(e);
            break;
        case SDL_KEYUP:
            e.event_t = Event::STOP_MOVE_DOWN;
               addEvent(e);
            break;
        }
        break;
    case SDLK_d:
        switch (event->type)
        {
        case SDL_KEYDOWN:
        {
            e.event_t = Event::START_MOVE_RIGHT;
            addEvent(e);//event zwiazany z ruchem
            addEvent(createEvent(Entity::master,Event::START_MOVE_RIGHT_ANIM));//event zwiazany z animacja
        }
            break;
        case SDL_KEYUP:
            e.event_t = Event::STOP_MOVE_RIGHT;
               addEvent(e);
            break;
        }
        break;
    case SDLK_a:
        switch (event->type)
        {
        case SDL_KEYDOWN:
            e.event_t = Event::START_MOVE_LEFT;
               addEvent(e);
            break;
        case SDL_KEYUP:
            e.event_t = Event::STOP_MOVE_LEFT;
               addEvent(e);
        }
        break;
    default:
        break;
    }
 
}
} // namespace EventSystem