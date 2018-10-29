#pragma once

#include "../System.h"
#include "../Entity.h"

#define CONTROL_MASK (COMPONENT_POSITION | COMPONENT_DISPLACEMENT)

namespace ControlSystem
{

void update()
{
    if (Entity::master != -1 && (Entity::mask[Entity::master] & CONTROL_MASK) == CONTROL_MASK)
    {
        Entity::position[Entity::master].pos += Entity::displacement[Entity::master].vel.normalize().multiply_by_scalar(Entity::displacement[Entity::master].v);
    }
};
void eventsHandling(event_obj event)
{
    switch (event.event_t)
    {
    case Event::START_MOVE_RIGHT:
        Entity::displacement[event.entity_id].vel.x = 1;
        break;
    case Event::STOP_MOVE_RIGHT:
        Entity::displacement[event.entity_id].vel.x = 0;
        break;
    case Event::START_MOVE_LEFT:
        Entity::displacement[event.entity_id].vel.x = -1;

        break;
    case Event::STOP_MOVE_LEFT:
        Entity::displacement[event.entity_id].vel.x = 0;
        break;
    case Event::START_MOVE_UP:
        Entity::displacement[event.entity_id].vel.y = -1;
        break;
    case Event::STOP_MOVE_UP:
        Entity::displacement[event.entity_id].vel.y = 0;
        break;
    case Event::START_MOVE_DOWN:
        Entity::displacement[event.entity_id].vel.y = 1;
        break;
    case Event::STOP_MOVE_DOWN:
        Entity::displacement[event.entity_id].vel.y = 0;
        break;
    default:
        break;
    }
}
} // namespace ControlSystem