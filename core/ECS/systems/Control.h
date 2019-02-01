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
        Entity::displacement[Entity::master].vel=vect();//tak nie powinnismy robic, bo nie wiadomo czy gdzies jeszcze przed renderowaniem klatki informacja o przesunieciu nie jest potrzebna
       // std::cout<<Entity::position[Entity::master].pos<<"\n";
    }
};

void eventsHandling(event_obj& event)
{
    /*
    podejscie zaproponowane w tej funkcji jest niewłaściwe, ale dla celów dalszych rozkmin zostawiłem je - tylko dla START_MOVE_RIGHT.
    chodzi o to, że przy jednym poruszającym się obiekcie każdy typ eventu musiałby mieć swój counter. gdyby mieć dwa takie obiekty
    (w sensie poruszające się), to każdy z nich musiałby mieć własny counter.

    ogólnie, idea dotyczyła tego, że każdy system miał sam ogarniać czas z jakim reaguje na eventy - porównaj z animacjami.
    aktualnie wydaje mi się, że to podejście jest niewłaściwe, bo komplikuje znacząco kod. zupełnie wystarczające będzie w main loop
    wprowadzić kontrolę by co 16ms renderować klatkę.
    */
    static int counter = 0;
    switch (event.event_t)
    {
    case Event::START_MOVE_RIGHT:
            {
                counter++;
                if (counter == 10){
                    Entity::displacement[event.entity_id].vel.x = 1;
                    event.alive = false;
                    counter = 0;
                }        
            }
        break;
    case Event::STOP_MOVE_RIGHT:
        Entity::displacement[event.entity_id].vel.x = 0;
        event.alive = false;
        break;
    case Event::START_MOVE_LEFT:
        Entity::displacement[event.entity_id].vel.x = -1;
        event.alive = false;
        break;
    case Event::STOP_MOVE_LEFT:
        Entity::displacement[event.entity_id].vel.x = 0;
        event.alive = false;
        break;
    case Event::START_MOVE_UP:
        Entity::displacement[event.entity_id].vel.y = -1;
        event.alive = false;
        break;
    case Event::STOP_MOVE_UP:
        Entity::displacement[event.entity_id].vel.y = 0;
        event.alive = false;
        break;
    case Event::START_MOVE_DOWN:
        Entity::displacement[event.entity_id].vel.y = 1;
        event.alive = false;
        break;
    case Event::STOP_MOVE_DOWN:
        Entity::displacement[event.entity_id].vel.y = 0;
        event.alive = false;
        break;
    default:
        break;
    }
}
} // namespace ControlSystem