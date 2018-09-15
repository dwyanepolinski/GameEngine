
#ifndef GAMEENGINE_CONTROL_H
#define GAMEENGINE_CONTROL_H

#include "../System.h"

namespace ControlSystem{
    
#define CONTROL_MASK (COMPONENT_POSITION|COMPONENT_DISPLACEMENT)
    
    void update(){
        
        if(Entity::master != -1 && (Entity::mask[Entity::master] & CONTROL_MASK) == CONTROL_MASK){
            Entity::position[Entity::master].pos += Entity::displacement[Entity::master].vel.normalize().multiply_by_scalar(Entity::displacement[Entity::master].v);
        }
    }
    
    void keydown(int key){
        switch(key){
            case SDLK_w:
                Entity::displacement[Entity::master].vel.y = -1;
                break;
            case SDLK_s:
                Entity::displacement[Entity::master].vel.y = 1;
                break;
            case SDLK_a:
                Entity::displacement[Entity::master].vel.x = -1;
                break;
            case SDLK_d:
                Entity::displacement[Entity::master].vel.x = 1;
                break;
            default:
                break;
        }
    }
    
    void keyup(int key){
        switch(key){
            case SDLK_w:
                Entity::displacement[Entity::master].vel.y = 0;
                break;
            case SDLK_s:
                Entity::displacement[Entity::master].vel.y = 0;
                break;
            case SDLK_a:
                Entity::displacement[Entity::master].vel.x = 0;
                break;
            case SDLK_d:
                Entity::displacement[Entity::master].vel.x = 0;
                break;
            default:
                break;
        }
    }
    
    void event_handler(SDL_Event *event){
        if(Entity::master == -1)
            return;
            
        switch (event->type) {
            case SDL_KEYUP: keyup(event->key.keysym.sym);
            break;
            case SDL_KEYDOWN: keydown(event->key.keysym.sym);
            break;
        }
    }
    
}



#endif