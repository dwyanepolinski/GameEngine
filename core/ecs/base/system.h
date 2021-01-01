#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include "../../context.h"


class SystemInterface {
    protected:

    int _mask = 0;
    int _id; 

    public:

    virtual ~SystemInterface() {};
    const int id() { return _id; }
    const int mask() { return _mask; }
    virtual void handle_events() = 0;
    virtual void update() = 0;
};

namespace SystemManager {
    namespace {
        std::vector<SystemInterface*> systems;
        std::vector<std::vector<int>> system_entity_rel;
        GameContext* ctx;
    }

    void destroy() {
        for (auto system : SystemManager::systems)
            delete system;
        systems.clear();
    }

    const std::vector<int> get_system_entities(const int system_id) {
        if(!(0 <= system_id && system_id < system_entity_rel.size()))
            return std::vector<int>();
        return system_entity_rel[system_id];
    }

    void check_entity(const int entity_id, const int entity_mask) {
        for(int system_id = 0; system_id < systems.size(); system_id++) {
            auto system_mask = systems[system_id]->mask();
            auto system_entities = system_entity_rel[system_id];
            bool is_paired_mask = (entity_mask & system_mask) == system_mask;
            bool is_paired_rel = false;
            int is_paired_rel_position;

            for(int index = 0; index < system_entities.size(); index++) {
                if(system_entities[index] == entity_id) {
                    is_paired_rel = true;
                    is_paired_rel_position = index;
                    break;
                }
            }

            if(!is_paired_rel && is_paired_mask)
                system_entity_rel[system_id].emplace_back(entity_id);
            else if(is_paired_rel && !is_paired_mask)
                system_entity_rel[system_id].erase(system_entity_rel[system_id].begin() + is_paired_rel_position);
        }
    }

    void init(GameContext *c) {
        // system_entity_rel = std::vector<std::vector<int>>();
        ctx = c;
    }

    void handle_events() {
        for(unsigned int i = 0; i < systems.size(); i++)
            systems[i]->handle_events();
    }

    void update() {
        for(unsigned int i = 0; i < systems.size(); i++)
            systems[i]->update();
    }
}

class System: public SystemInterface {

    public:

    System(){
        SystemManager::systems.emplace_back(this);
        SystemManager::system_entity_rel.emplace_back(std::vector<int>());
        _id = SystemManager::systems.size() - 1;
    }
};

#endif