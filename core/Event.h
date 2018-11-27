#ifndef GAMEENGINE_EVENT_H
#define GAMEENGINE_EVENT_H

#include <vector>
#define MAX_EVENTS 300

namespace EventSystem{

    struct BaseEvent{
        unsigned int type;
        int entity = -1;
        int second_entity = -1;
        bool alive = false;
    };

    unsigned int max_id = 0;
    std::vector<BaseEvent> events(MAX_EVENTS);

    int register_event(unsigned int type, unsigned int entity, int second_entity = -1){
        for(unsigned int id = 0; id < MAX_EVENTS; id++){
            if(!events[id].alive){
                events[id].type = type;
                events[id].entity = entity;
                events[id].alive = true;
                events[id].second_entity = second_entity;
                if(id > max_id)
                    max_id = id;
                return id;
            }
        }
        return -1;
    }

    void kill_event(unsigned int id){
        if(id > MAX_EVENTS - 1 && events[id].alive)
            return;
        events[id].alive = false;
        if(id = max_id){
            for(unsigned int idx = max_id - 1; idx >= 0 ; idx--){
                if(events[idx].alive){
                    max_id = idx;
                    return;
                }
            }
            max_id = 0;
        }
    }

    void update(){
        if(!max_id)
            return;

        for(unsigned int id = 0; id < max_id + 1; id++)
            if(events[id].alive){
                events[id].alive = false;
            }
        max_id = 0;
    }

}

#endif