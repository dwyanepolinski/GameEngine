#ifndef ECS_SYSTEMS_CONTROL_H
#define ECS_SYSTEMS_CONTROL_H

#include "../manager.h"


class ControlSystem: public System {
    public:

    ControlSystem() : System() {
        _mask = (Components::POSITION|Components::DISPLACEMENT);
    }

    void handle_events() {
        if(this->idle())
            return;

        switch (ECSManager::ctx->sdl_event->type) {
            case SDL_KEYUP: {
                for(auto const entity_id : SystemManager::get_system_entities(this->id())){
                    auto displacement_component = (DisplacementComponent*)ComponentManager::get(entity_id, Components::DISPLACEMENT);
                    if(displacement_component->controllable)
                        keyup(ECSManager::ctx->sdl_event->key.keysym.sym, displacement_component);
                }
                return;
            }
            case SDL_KEYDOWN: {
                for(auto const entity_id : SystemManager::get_system_entities(this->id())){
                    auto displacement_component = (DisplacementComponent*)ComponentManager::get(entity_id, Components::DISPLACEMENT);
                    if(displacement_component->controllable)
                        keydown(ECSManager::ctx->sdl_event->key.keysym.sym, displacement_component);
                }
                return;
            }
        }
    }

    void keyup(const int key, DisplacementComponent* cmp) {
        switch(key){
            case SDLK_w:
                cmp->velocity.y = 0;
                return;
            case SDLK_s:
                cmp->velocity.y = 0;
                return;
            case SDLK_a:
                cmp->velocity.x = 0;
                return;
            case SDLK_d:
                cmp->velocity.x = 0;
                return;
            default:
                return;
        }
    }

    void keydown(const int key, DisplacementComponent* cmp) {
        switch(key){
            case SDLK_w:
                cmp->velocity.y = -1;
                return;
            case SDLK_s:
                cmp->velocity.y = 1;
                return;
            case SDLK_a:
                cmp->velocity.x = -1;
                return;
            case SDLK_d:
                cmp->velocity.x = 1;
                return;
            default:
                return;
        }
    }

    void update() {
        for(auto const entity_id : SystemManager::get_system_entities(this->id())){
            auto displacement_component = (DisplacementComponent*)ComponentManager::get(entity_id, Components::DISPLACEMENT);
            if(displacement_component->controllable) {
                vect movement = displacement_component->velocity.normalize().multiply_by_scalar(displacement_component->v * ECSManager::ctx->dt());
                auto position_component = (PositionComponent*)ComponentManager::get(entity_id, Components::POSITION);
                position_component->coordinates += movement;
            }
        }
    }

}; 

#endif
