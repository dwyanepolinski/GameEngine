#ifndef ECS_ENTITY_H
#define ECS_ENTITY_H

#include "../../context.h"

class Entity;

namespace EntityManager {
    namespace {
        IList<Entity*> entities;
        GameContext ctx;
    }

    void init(const GameContext c) {
        // entities = IList<Entity*>();
        ctx = c;
    }

    const int add(Entity *e) { return entities.add(e); }
    void remove(const int id) { entities.remove(id); }
    const int count() { return entities.count(); }

    Entity* get_by_id(const int id) {
        if(entities.exists(id))
            return entities[id];
        return nullptr;
    }
}

class Entity {
    unsigned int _mask, _id;
    std::string _name;

    public:

    Entity() = default;

    Entity(std::string name) {
        _name = name;
        _mask = 0;
        _id = EntityManager::add(this);
    }

    const int id() { return _id; }
    const int mask() { return _mask; }
    const std::string name() { return _name; }
    void set_name(const std::string name) { _name = name; }

    void add_component(const int component_id) { 
        if((_mask & component_id) != component_id)
            _mask |= component_id; 
    }
    void remove_component(const int component_id) {
        if((_mask & component_id) == component_id) 
            _mask ^= component_id; 
    }
};

#endif