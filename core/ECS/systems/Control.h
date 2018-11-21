
#ifndef GAMEENGINE_CONTROL_H
#define GAMEENGINE_CONTROL_H

#include "../System.h"
#include "../Entity.h"


namespace ControlSystem{
    
#define CONTROL_MASK (COMPONENT_POSITION|COMPONENT_DISPLACEMENT)

    unsigned int map_entity_id = 0;
    bool camera_vertical_move = false;
    bool camera_horizontal_move = false;
    
    void update(){
        
        if(Entity::master != -1 && (Entity::mask[Entity::master] & CONTROL_MASK) == CONTROL_MASK){
            
            vect movement = Entity::displacement[Entity::master].vel.normalize().multiply_by_scalar(Entity::displacement[Entity::master].v * Game::dt);
            vect camera_movement;

            if(camera_horizontal_move){
                camera_movement.x = -movement.x;
                movement.x = 0;
            }
            if(camera_vertical_move){
                camera_movement.y = -movement.y;
                movement.y = 0;
            }

            Entity::position[Entity::master].pos += movement;
            Entity::position[map_entity_id].pos += camera_movement;
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

    void camera(){
        camera_vertical_move = false;
        camera_horizontal_move = false;
        for(unsigned int id = 0; id < EventSystem::max_id; id++){
            if(EventSystem::events[id].entity == Entity::master && EventSystem::events[id].state && EventSystem::events[id].type == 0){

                if(EventSystem::events[id].second_entity == 4 && Entity::displacement[Entity::master].vel.x == -1){
                    if(Entity::position[Entity::master].pos.x < 0)
                        Entity::displacement[Entity::master].vel.x = 0;
                    else if(Entity::position[map_entity_id].pos.x < 0)
                        camera_horizontal_move = true;
                }

                if(EventSystem::events[id].second_entity == 5 && Entity::displacement[Entity::master].vel.x == 1){
                    if(Entity::position[Entity::master].pos.x + Entity::size[Entity::master].w > 800)
                        Entity::displacement[Entity::master].vel.x = 0;
                    else if(Entity::position[map_entity_id].pos.x > 800 - Entity::size[map_entity_id].w)
                        camera_horizontal_move = true;
                }

                if(EventSystem::events[id].second_entity == 2 && Entity::displacement[Entity::master].vel.y == -1){
                    if(Entity::position[Entity::master].pos.y < 0)
                        Entity::displacement[Entity::master].vel.y = 0;
                    else if(Entity::position[map_entity_id].pos.y < 0)
                        camera_vertical_move = true;
                }

                if(EventSystem::events[id].second_entity == 3 && Entity::displacement[Entity::master].vel.y == 1){
                    if(Entity::position[Entity::master].pos.y + Entity::size[Entity::master].h > 600)
                        Entity::displacement[Entity::master].vel.y = 0;
                    else if(Entity::position[map_entity_id].pos.y > 600 - Entity::size[map_entity_id].h)
                        camera_vertical_move = true;
                }

            }
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
        
        camera();
    }
    
}

#endif