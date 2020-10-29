#ifndef ECS_MANAGER_H
#define ECS_MANAGER_H

#include "base/entity.h"
#include "base/component.h"
#include "base/system.h"

#define ATEXTURE       0
#define AENTITY        1
#define ACOMPONENT     2

namespace ECSManager {

    IList<SDL_Texture*> textures_db;
    GameContext ctx;

    namespace {
        Entity* current_entity = nullptr;
        Component* current_component = nullptr;
    }

    void init(const GameContext c) {
        textures_db = IList<SDL_Texture*>();
        ctx = c;

        EntityManager::init(c);
        ComponentManager::init(c);
        SystemManager::init(c);
    }

    void load_texture(std::string file) {
        SDL_Surface *load_file = SDL_LoadBMP(&(file)[0]);
        auto texture = SDL_CreateTextureFromSurface(ctx.renderer(), load_file);
        textures_db.add(texture);
        SDL_FreeSurface(load_file);
    }

    bool add_entity_component(const int entity_id, const int component_id) {
        Entity* e = EntityManager::get_by_id(entity_id);
        if(e != nullptr){
            ComponentManager::add(entity_id, component_id);
            e->add_component(component_id);
            SystemManager::check_entity(entity_id, e->mask());
            return true;
        }
        return false;
    }

    void remove_entity_component(const int entity_id, const int component_id) {
        Entity* e = EntityManager::get_by_id(entity_id);
        if(e != nullptr){
            ComponentManager::remove(e->id(), component_id);
            e->remove_component(component_id);
            SystemManager::check_entity(entity_id, e->mask());
        }
    }

    void remove_entity(const int entity_id) {
        Entity* e = EntityManager::get_by_id(entity_id);
        if(e != nullptr){
            ComponentManager::remove_all(entity_id);
            SystemManager::check_entity(entity_id, e->mask());
            EntityManager::remove(entity_id);
        }
    }

    void destroy() {
        SystemManager::destroy();
    }

    void set(const int variable, const std::string value) {
        switch (variable) {
        case ATEXTURE: {
            load_texture(value);
            break;
        }
        case AENTITY: {
            current_entity = new Entity(value);
            break;
        }
        case ACOMPONENT: {
            if(current_entity != nullptr) {
                int component_id = std::stoi(value);
                add_entity_component(current_entity->id(), component_id);
                Component* c = ComponentManager::get(current_entity->id(), component_id);
                if(c != nullptr)
                    current_component = c;
            }
            break;
        }
        default: {
            if(current_entity != nullptr)
                current_component->set(variable, value);
            break;
        }
        }
    }
}

#endif
