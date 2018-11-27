
#ifndef GAMEENGINE_CONTROL_H
#define GAMEENGINE_CONTROL_H

#include "../System.h"
#include "../Entity.h"
#include "Collision.h"


namespace ControlSystem{
    
#define CONTROL_MASK (COMPONENT_POSITION|COMPONENT_DISPLACEMENT)

    namespace _private{
        bool camera_vertical_move = false;
        bool camera_horizontal_move = false;
        vect camera_movement;
    }

    unsigned int map_entity_id = 0;
    
    void update(){
        
        if(Entity::master != -1 && (Entity::mask[Entity::master] & CONTROL_MASK) == CONTROL_MASK){
            vect movement = Entity::displacement[Entity::master].vel.normalize().multiply_by_scalar(Entity::displacement[Entity::master].v * Game::dt);
            _private::camera_movement.zero();

            if(_private::camera_horizontal_move){
                _private::camera_movement.x = -movement.x;
                movement.x = 0;
            }
            if(_private::camera_vertical_move){
                _private::camera_movement.y = -movement.y;
                movement.y = 0;
            }

            Entity::position[Entity::master].pos += movement;
            Entity::position[map_entity_id].pos += _private::camera_movement;
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
        _private::camera_vertical_move = false;
        _private::camera_horizontal_move = false;
        for(unsigned int id = 0; id < EventSystem::max_id; id++){
            if(EventSystem::events[id].entity == Entity::master && EventSystem::events[id].alive && EventSystem::events[id].type == CollisionSystem::COLLISION_EVENT){

                if(EventSystem::events[id].second_entity == CollisionSystem::_private::cam_bbox_left && Entity::displacement[Entity::master].vel.x == -1){
                    if(Entity::position[Entity::master].pos.x < 0)
                        Entity::displacement[Entity::master].vel.x = 0;
                    else if(Entity::position[map_entity_id].pos.x < 0)
                        _private::camera_horizontal_move = true;
                }

                if(EventSystem::events[id].second_entity == CollisionSystem::_private::cam_bbox_right && Entity::displacement[Entity::master].vel.x == 1){
                    if(Entity::position[Entity::master].pos.x + Entity::size[Entity::master].w > (int) Game::window_width)
                        Entity::displacement[Entity::master].vel.x = 0;
                    else if(Entity::position[map_entity_id].pos.x > (int) Game::window_width - Entity::size[map_entity_id].w)
                        _private::camera_horizontal_move = true;
                }

                if(EventSystem::events[id].second_entity == CollisionSystem::_private::cam_bbox_top && Entity::displacement[Entity::master].vel.y == -1){
                    if(Entity::position[Entity::master].pos.y < 0)
                        Entity::displacement[Entity::master].vel.y = 0;
                    else if(Entity::position[map_entity_id].pos.y < 0)
                        _private::camera_vertical_move = true;
                }

                if(EventSystem::events[id].second_entity == CollisionSystem::_private::cam_bbox_bottom && Entity::displacement[Entity::master].vel.y == 1){
                    if(Entity::position[Entity::master].pos.y + Entity::size[Entity::master].h > (int) Game::window_heigth)
                        Entity::displacement[Entity::master].vel.y = 0;
                    else if(Entity::position[map_entity_id].pos.y > (int) Game::window_heigth - Entity::size[map_entity_id].h)
                        _private::camera_vertical_move = true;
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
        
        if(Game::camera)
            camera();
    }
    
}

#endif