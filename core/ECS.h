//
// Created by john on 14.05.18.
//

#ifndef GAMEENGINE_ECS_H
#define GAMEENGINE_ECS_H

#include <iostream>
#include <cassert>
#include <vector>
#include <map>

class Entity;

class Component {

public:
    virtual ~Component(){};

    const Entity* entity;
    char* name = nullptr;
    virtual void load(char *_load) {};

};



class Entity {

public:
    int id = 0;
    char *name;

    Entity();
    virtual ~Entity();

    template<typename T> bool in_component(){
        char* component_tag = (char *) typeid(T).name();
        return components.find(component_tag) != components.end();
    }

    template<typename T> bool add_component() {
        if(in_component<T>())
            return false;
        T* component = new T();
        component->entity = this;
        components.insert(std::make_pair((char *) typeid(T).name(), component));
        return true;
    }

    template<typename T> T* get_component() {
        assert(in_component<T>() && "[CRITICAL] Entity has no given component");
        return (T*) components[(char *) typeid(T).name()];
    }

    template<typename T> bool remove_component() {
        if(!in_component<T>())
            return false;
        components.erase((char *) typeid(T).name());
        return true;
    }

    virtual void load(char* _name);
    std::map<char*, Component*> components;
    static void definition_file_reader(Entity* entity, const std::string key, const std::string value);
};

class ECS {

public:
    static std::vector<Entity*> entities;

    template<typename T> static std::vector<Entity *> filter_entities(std::vector<Entity *> entities_list = ECS::entities){
        std::vector<Entity*> filtered_entities;

        for(auto const& entity: entities_list){
            if(entity->in_component<T>())
                filtered_entities.push_back(entity);
        }
        return filtered_entities;
    }
};


#endif //GAMEENGINE_ECS_H
