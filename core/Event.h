#ifndef GAMEENGINE_EVENT_H
#define GAMEENGINE_EVENT_H

#include <vector>
#define MAX_EVENTS 300

namespace EventSystem{

    struct BaseEvent{
        unsigned int type;
        int entity = -1;
        int second_entity = -1;
        unsigned int state = 0;
    };

    unsigned int max_id = 0;
    std::vector<BaseEvent> events(MAX_EVENTS);

    int register_event(unsigned int type, unsigned int state, unsigned int entity, int second_entity = -1){
        for(unsigned int id = 0; id < MAX_EVENTS; id++){
            if(!events[id].state){
                events[id].type = type;
                events[id].entity = entity;
                events[id].state = state;
                events[id].second_entity = second_entity;
                if(id > max_id)
                    max_id = id;
                return id;
            }
        }
        return -1;
    }

    void drop_event(unsigned int id){
        if(id > MAX_EVENTS - 1 && events[id].state)
            return;
        events[id].state = 0;
    }

    void update(){
        if(!max_id)
            return;

        unsigned int range = max_id + 1;
        unsigned int last_alive = 0;

        for(unsigned int id = 0; id < range; id++)
            if(events[id].state > 0){
                events[id].state--;
                if(events[id].state)
                    last_alive = id;
            }
        max_id = last_alive;
    }

}

#endif