#ifndef EVENT_H
#define EVENT_H

#include <vector>
#define MAX_EVENTS 1024

class Event;

namespace EventSystem {
    std::vector<Event*> bus(MAX_EVENTS);

    void emit(Event *e) {
        bus.emplace_back(e);
    }

    void clear() {
        for(unsigned int i = 0; i < bus.size(); i++) {
            delete bus[i];
        }
        bus.clear();
    }
}

#endif